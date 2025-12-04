#include <stdio.h>
#include <stdlib.h> 
#define TRUE 1
#define FALSE 0

typedef struct elemento{
	int dado;
	struct elemento *prox;
} *ApElemento; 

typedef struct{
	ApElemento ini;
	ApElemento fim; 
} Fila;

Fila criaFila();
int filaVazia (Fila f);
Fila insereFila (Fila f, int e);
Fila retiraFila (Fila f, int *e);
void imprimeFila (Fila f);

Fila criaFila(){
	Fila f;
	f.ini = NULL;
	f.fim = NULL;
	return (f);
}

int filaVazia (Fila f){
	if (f.ini == NULL)
		return (TRUE);
	else
		return (FALSE);
}

Fila insereFila (Fila f, int e){
	ApElemento novo;
	novo = malloc(sizeof(struct elemento));
	novo -> dado = e;
	novo -> prox = NULL; 
	if (filaVazia(f)){
		f.ini = novo;
		f.fim = novo;
	}else{
		f.fim->prox = novo;
		f.fim = novo;
	}
	return (f); 
}

Fila retiraFila (Fila f, int *e){
	ApElemento ap; 
	if (!filaVazia (f)){
		*e = f.ini->dado;
		ap = f.ini;
		f.ini = f.ini->prox;
		free (ap);
		if (filaVazia (f))
			f.fim = NULL;
	}else{
		*e = -1;
		printf("\nFila Vazia!");
	}
	return (f); 
}

void imprimeFila (Fila f){
	ApElemento ap; 
	
	printf("\nConteúdo da Fila: ");
	ap = f.ini;
	while (ap != NULL){
	    printf("%d ", ap->dado);
	    ap = ap->prox;
	    }
	printf("\n");
}

int main(){

	Fila f = criaFila();
	int opcao;
	int valor; 
	int retirado;

	do {
		printf("\n----- MENU DE OPÇÕES -----\n");
		printf("1 - Inserir um elemento no final da fila\n");
		printf("2 - Retirar um elemento do início da fila\n");
		printf("3 - Imprimir o conteúdo da fila\n");
		printf("0 - Sair\n");
		printf("Escolha a opção: ");

		if (scanf("%d", &opcao) != 1) {
			while (getchar() != '\n'); 
			opcao = -1;
		}

		switch (opcao) {
			case 1:
				printf("Digite o valor inteiro a ser inserido: ");
				if (scanf("%d", &valor) == 1) {
					f = insereFila(f, valor);
					printf("Elemento %d inserido no final da fila.\n", valor);
				} else {
					while (getchar() != '\n'); 
					printf("Entrada inválida.\n");
				}
				break;
			case 2: 
				f = retiraFila(f, &retirado);
				if (retirado != -1) {
					printf("Elemento %d retirado do início da fila.\n", retirado);
				}
				break;
			case 3:
				imprimeFila(f);
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