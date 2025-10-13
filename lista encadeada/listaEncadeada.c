/*Implementar um programa que gerencia uma lista encadeada ordenada com alocação dinâmica.
Cada elemento da lista deve conter um número inteiro.
Os elementos devem ser inseridos em ordem crescente. Por exemplo, de for inserida a sequência 5, 3, 9, 4, ao imprimir o conteúdo da lista, deve aparecer 3, 4, 5, 9.
O programa deve oferecer ao usuário as operações:
- Inserir elemento na lista;
- Retirar elemento da lista;
- Buscar um elemento informado está na lista, retornando o endereço do elemento se ele existir na lista, ou NULL se não existir;
- Imprimir o conteúdo da lista;
- Contar o número de elementos da lista.
*/
#include <stdio.h>
#include <stdlib.h>

struct elemento {
    int dado; 
    struct elemento *prox; 
};

typedef struct elemento Nodo;
typedef Nodo *Lista; 

Lista criaLista();
Lista insereLista(Lista l, int e);
Lista retiraLista(Lista l, int e);
Lista buscaLista(Lista l, int e);
void imprimeLista(Lista l);
int contaLista(Lista l);

Lista criaLista() {
    return NULL; 
} 

Lista insereLista(Lista l, int e) {
    Lista p, ant, novo;

    // 1. Aloca o novo nodo [5, 17]
    novo = (Lista) malloc(sizeof(struct elemento)); 
    if (novo == NULL) {
        fprintf(stderr, "Erro na alocação de memória!\n");
        return l;
    }
    novo->dado = e;

    // 2. Procura o ponto de inserção [18]
    p = l;
    ant = NULL; // Ponteiro para o anterior, inicialmente NULL.

    // Percorre a lista enquanto não chega ao fim E o dado atual for menor que 'e' [18]
    while ((p != NULL) && (p->dado < e)) {
        ant = p; 
        p = p->prox; 
    }

    // 3. Realiza a inserção
    
    if (ant == NULL) {
        // Caso 1: Lista vazia ou inserção no início (antes do primeiro elemento) [19]
        novo->prox = l;
        l = novo; // O novo nó se torna o início da lista
    } else {
        // Caso 2: Inserção no meio ou no final [20]
        ant->prox = novo; // O próximo do anterior é o novo nó
        novo->prox = p;   // O próximo do novo nó é 'p' (o nó que era maior ou NULL)
    }
    
    return l; 
} // [15, 18]

void imprimeLista(Lista l) {
    Lista p; // Ponteiro auxiliar para percorrer a lista [10]

    printf("\nItens da lista: ");
    p = l; 
    
    // Percorre enquanto não chegar ao final da lista (NULL) [10]
    while (p != NULL) {
        printf("%d", p->dado); 
        p = p->prox; // Avança o ponteiro [11]
        if (p != NULL) {
            printf(", ");
        }
    }
    printf("\n");
} // [10, 11]

Lista retiraLista (Lista l, int e) {
    Lista p,    // Ponteiro para o elemento atual [22]
          ant;  // Ponteiro para o elemento anterior [22]

    p = l;
    ant = NULL; 

    // 1. Procura o elemento e [22]
    while ((p!=NULL) && (p->dado != e)) {
        ant = p; 
        p = p->prox;
    }

    // 2. Verifica se o elemento foi encontrado
    if (p != NULL) { 
        // 3. Remove
        
        // Caso a: Removendo o primeiro elemento (ant é NULL) [22]
        if (ant == NULL) { 
            l = p->prox; // Atualiza o início da lista
            free (p); 
        } 
        // Caso b: Removendo do meio ou do final [22]
        else {
            ant->prox = p->prox; // Conecta o anterior ao próximo do nó removido
            free(p); 
        }
    } else {
        printf("\nElemento %d não encontrado na lista.\n", e);
    }
    
    return(l); // Retorna o novo endereço de início da lista [21]
}

Lista buscaLista(Lista l, int e) {
    Lista p; // Ponteiro para percorrer a lista [13]

    p = l; 
    
    // Percorre a lista enquanto não chega ao final E não encontra o elemento [13]
    while ((p != NULL) && (p->dado != e)) {
        p = p->prox; 
    }
    return (p); // Retorna o endereço do nodo ou NULL [13]
}

int contaLista(Lista l) {
    Lista p;
    int cont = 0; 

    p = l; 
    
    // Percorre a lista até o fim [12]
    while (p != NULL) {
        cont++; 
        p = p->prox; 
    }
    return cont; 
} // [12]

// Estrutura básica do menu e chamada das funções
int main() {
    Lista minhaLista;
    int valor, opcao;
    Lista encontrado;

    minhaLista = criaLista(); // Inicializa a lista vazia [8]

    do {
        printf("\n\n--- MENU DE OPÇÕES ---\n");
        printf("1 - Inserir elemento na lista\n");
        printf("2 - Retirar elemento da lista\n");
        printf("3 - Buscar um elemento\n");
        printf("4 - Imprimir o conteúdo da lista\n");
        printf("5 - Contar o número de elementos\n");
        printf("0 - Sair\n");
        printf("Escolha a opção: ");
        
        // Simples leitura de opção
        if (scanf("%d", &opcao) != 1) {
             while (getchar() != '\n'); // Limpa o buffer
             opcao = -1; // Opção inválida
        }

        switch (opcao) {
            case 1:
                printf("Digite o valor inteiro a ser inserido (em ordem crescente): ");
                scanf("%d", &valor);
                // A função insereLista retorna o novo endereço da lista, que deve ser capturado [2, 17]
                minhaLista = insereLista(minhaLista, valor); 
                break;

            case 2:
                printf("Digite o valor a ser retirado: ");
                scanf("%d", &valor);
                minhaLista = retiraLista(minhaLista, valor);
                break;

            case 3:
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &valor);
                encontrado = buscaLista(minhaLista, valor);
                if (encontrado != NULL) {
                    printf("Elemento %d encontrado no endereço: %p\n", valor, (void *)encontrado);
                } else {
                    printf("Elemento %d não encontrado (Retorno: NULL)\n", valor);
                }
                break;

            case 4:
                imprimeLista(minhaLista);
                break;

            case 5:
                printf("Total de elementos na lista: %d\n", contaLista(minhaLista));
                break;

            case 0:
                printf("Encerrando o programa.\n");
                // Em um programa real, a memória deveria ser liberada aqui antes de sair.
                break;

            default:
                printf("Opção inválida.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
