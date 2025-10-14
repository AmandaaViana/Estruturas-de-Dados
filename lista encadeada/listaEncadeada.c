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
    
    novo = malloc(sizeof(struct elemento));
    novo -> dado = e;
    
    p = l;
    ant = p;
    while ((p != NULL) && (p->dado <e)){
		ant = p;
		p = p ->prox;
		}
	if(p != ant){
		ant->prox = novo;
		} else {
			l = novo;
		}
		novo->prox = p;
		return l;
}

void imprimeLista(Lista l) {
    Lista p;

    printf("\nItens da lista: ");
    p = l; 

    if (p == NULL) {
        printf("Lista vazia.");
    }

    while (p != NULL) {
        printf("%d", p->dado); 
        p = p->prox;

        if (p != NULL) {
            printf(", ");
        }
    }
    printf("\n");
}

Lista retiraLista (Lista l, int e) {
    Lista p,ant;  

    p = l;
    ant = NULL; 

    while ((p!=NULL) && (p->dado != e)) {
        ant = p; 
        p = p->prox;
    }

    if (p != NULL) { 
        if (ant == NULL) { 
            l = p->prox;
            free (p); 
        }else {
            ant->prox = p->prox;
            free(p); 
        }
    } else {
        printf("\nElemento %d não encontrado na lista.\n", e);
    }

    return(l);
}

Lista buscaLista(Lista l, int e) {
    Lista p;

    p = l; 

    while ((p != NULL) && (p->dado != e)) {
        p = p->prox; 
    }
    return (p);
}

int contaLista(Lista l) {
    Lista p;
    int cont = 0; 

    p = l; 

    while (p != NULL) {
        cont++; 
        p = p->prox; 
    }
    return cont; 
}

int main() {
    Lista minhaLista;
    int valor, opcao;
    Lista encontrado;

    minhaLista = criaLista();

    do {
        printf("\n----- MENU DE OPÇÕES -----\n");
        printf("1 - Inserir elemento na lista\n");
        printf("2 - Retirar elemento da lista\n");
        printf("3 - Buscar um elemento\n");
        printf("4 - Imprimir o conteúdo da lista\n");
        printf("5 - Contar o número de elementos\n");
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
                break;

            default:
                printf("Opção inválida.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
