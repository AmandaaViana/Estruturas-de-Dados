#include <stdio.h>
#include <stdlib.h>
#define TAM_HASH 10 

struct elemento {
    int dado;          
    struct elemento *prox; 
};

typedef struct elemento Nodo;
typedef Nodo *Lista;
Lista criaLista();
void imprimeLista (Lista l);
Lista buscaLista (Lista l, int e);
Lista insereLista (Lista l, int e);
Lista retiraLista (Lista l, int e);

int hash (int chave) {
    return (chave % TAM_HASH);
}

void criaHash (Lista *h) {
    int i;
    for (i = 0; i < TAM_HASH; i++) {
        h[i] = criaLista(); // Chama a rotina de lista vazia
    }
}

void insereHash (Lista *h, int valor) {
    int i;
    i = hash (valor);
    h[i] = insereLista (h[i], valor);
}

Lista buscaHash (Lista *h, int valor) {
    int i;
    i = hash (valor);
    return (buscaLista (h[i], valor));
}

void retiraHash (Lista *h, int valor) {
    int i;
    i = hash (valor);
    h[i] = retiraLista (h[i], valor);
}

void imprimeHash (Lista *h) {
    int i;
    printf("\n--- Imprimindo as listas do hash h ---\n");
    for (i = 0; i < TAM_HASH; i++) {
        printf("h[%d]: ", i);
        imprimeLista (h[i]);
        printf("\n");
    }
    printf("--------------------------------------\n");
}

Lista criaLista () {
    return NULL; 
}

Lista insereLista (Lista l, int e) {
    Lista novo;
    novo = (Lista) malloc(sizeof(struct elemento)); 
    novo->dado = e;                              
    novo->prox = l;                              
    return (novo);                               
}

Lista buscaLista (Lista l, int e) {
    Lista p = l; 
    while ((p != NULL) && (p->dado != e)) { 
        p = p->prox;
    }
    return (p); 
}

Lista retiraLista (Lista l, int e) {
    Lista p = l, ant = l;

    while ((p != NULL) && (p->dado != e)) {
        ant = p;
        p = p->prox;
    }

    if (p != NULL) {
        if (p == ant) { 
            l = p->prox;
        } else {
            ant->prox = p->prox;
        }
        free (p); 
    }
    return (l);
}

void imprimeLista (Lista l) {
    Lista p = l;
    while (p != NULL) { 
        printf("%d -> ", p->dado);
        p = p->prox; 
    }
    printf("NULL");
}

int main() {
   
    Lista Hash[TAM_HASH]; 
    int opcao, valor;
    Lista encontrado = NULL; // Variável para armazenar o resultado da busca (ponteiro para Nodo)

    criaHash(Hash);
    printf("Tabela Hash inicializada com %d posições.\n", TAM_HASH);

     do {
        printf("\n----- MENU DE OPÇÕES -----\n");
        printf("1 - Inserir elemento\n");
        printf("2 - Retirar elemento\n");
        printf("3 - Buscar um elemento\n");
        printf("4 - Imprimir o conteúdo\n");
        printf("0 - Sair\n");
        printf("Escolha a opção: ");

        if (scanf("%d", &opcao) != 1) {
             while (getchar() != '\n');
             opcao = -1;
        }

        switch (opcao) {
            case 1:
                printf("Digite o valor inteiro a ser inserido: ");
                scanf("%d", &valor);
                insereHash(Hash, valor); // 
                printf("Elemento %d inserido no Hash.\n", valor);
                break;

            case 2:
                printf("Digite o valor a ser retirado: ");
                scanf("%d", &valor);
                retiraHash(Hash, valor); // 
                printf("%d - Retirado.\n", valor);
                break;

            case 3:
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &valor);
                encontrado = buscaHash(Hash, valor);
                if (encontrado != NULL) {
                    printf("Elemento %d encontrado\n", valor);
                } else {
                    printf("Elemento %d não encontrado.\n", valor);
                }
                break;

            case 4:
                imprimeHash(Hash);
                break;
                
            case 0:
                printf("Encerrando o programa.\n");
                break;

            default:
                printf("Opção inválida.\n");
                break;
        }
    } while (opcao != 0);
    return 0;
}
