/*Faça um programa que implemente uma pilha com alocação dinâmica, para armazenar números inteiros.
O usuário deve poder incluir quantos elementos desejar na pilha.
As opções permitidas para o usuário são:
1 - Empilhar um elemento (inserir na pilha)
2 - Desempilhar um elemento (retirar o elemento do topo da pilha)
3 - Imprimir o conteúdo da pilha.*/

#include <stdio.h>
#include <stblib>

struct elemento {
	int dado;
	strutc elemento *prox;
	}

Pilha criaPilha();
Pilha empilha(Pilha p, int e);
Pilha desempilha(Pilha p, int *e);
void imprimePilha(Pilha p);

Pilha criaPilha(){
	return NULL;
	}
	
Pilha empilha(Pilha p, int e){
	Pilha novo;
	
	novo = malloc(sizeof(struct elemento));
	novo -> dado = e;
	novo -> prox = p;
	return (novo);
	}

Pilha desempilha (Pilha p, int *e){
	Pilha ap;
	if(!pilhaVazia(p)){
		*e = p->dado;
		ap = p;
		p = p->prox;
		free(ap);
	}else {
		*e = -1;
		printf("Pilha vazia");
		}
	return (p);
	}

void imprimePilha (Pilha p){
	Pilha ap;
	
	printf("Itens da pilha");
	ap = p;
	while (ap != NULL){
		printf("%d - ", ap->dado);
		ap = ap->prox;
		}
	printf("\n");
	}

int main(){
	
	
	
	
	
	
	do {
        printf("\n----- MENU DE OPÇÕES -----\n");
        printf("1 - Empilhar um elemento\n");
        printf("2 - Desempilhar um elemento\n");
        printf("3 - Imprimir o conteúdo da pilha\n");
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

