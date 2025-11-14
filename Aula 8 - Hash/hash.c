#include <stdio.h>
#include <stdlib.h>
#include "lista.c"

Lista h [TAM_HASH];
int hash(int chave);
void criaHash(Lista *h);
void insereHash(Lista *h, int valor);
Lista buscaHash(Lista *h);
void retiraHash(Lista *h, int valor);
void imprimeHash(Lista *h);

int hash(int chave){
	return (chave % TAM_HASH);
	}

void criaHash(Lista *h){
	int i;
	for (i=0; i<TAM_HASH; i++)
		h[i] = criaLista();
	}

void insereHash(Lista *h, int valor){
	int i;
	i = hash(valor);
	h[i] = insereLista(h[i],valor);
	}

Lista buscaHash(Lista *h){
	int i;
	i = hash(valor);
	h[i] = buscaHash(h[i], valor);
	}

void retiraHash(Lista *h, int valor){
	int i;
	i = hash(valor);
	h[i] = retiraHash(h[i], valor);
	}

void imprimeHash(Lista *h){
	int i;
	
	printf("\nListas do hash h");
	for(i=0; i<TAM_HASH; i++){
		printf("\nh[%d]: ", i)
		imprimeLista(h[i]);
		}
	
	}

int main() {
    
    Lista 

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
                
                break;

            case 2:
                printf("Digite o valor a ser retirado: ");
                scanf("%d", &valor);
               
                break;

            case 3:
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &valor);
             
                if (encontrado != NULL) {
                    printf("Elemento %d encontrado no endereço: %p\n", valor, (void *)encontrado);
                } else {
                    printf("Elemento %d não encontrado (Retorno: NULL)\n", valor);
                }
                break;

            case 4: //imprime
                
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


