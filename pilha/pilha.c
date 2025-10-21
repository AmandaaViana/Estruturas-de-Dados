#include <stdio.h>
#include <stdlib.h> 
#define TRUE 1
#define FALSE 0

typedef struct elemento{
	int dado;
	struct elemento *prox; 
} *Pilha;

int pilhaVazia (Pilha p); 
Pilha criaPilha();
Pilha empilha(Pilha p, int e);
Pilha desempilha(Pilha p, int *e);
void imprimePilha(Pilha p);

Pilha criaPilha(){
	return NULL;
}

 int pilhaVazia(Pilha p){
     if (p == NULL)
        return (TRUE);
     else
         return (FALSE);
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
		printf("\nPilha Vazia\n");
	}
	return (p); 
}

void imprimePilha (Pilha p){
	Pilha ap;
	
	printf("\nItens da pilha: ");
	ap = p;
	if (pilhaVazia(p)) {
	    printf("(Pilha vazia)");
	} else {
	    while (ap != NULL){
		    printf("\n %d", ap->dado);
		    ap = ap->prox;
	    }
	}
	printf("\n");
}

int main(){
	Pilha p = criaPilha(); 
	int opcao;
	int valor; 
	int e_retirado; 
	
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
            if (scanf("%d", &valor) == 1) {
                p = empilha(p, valor);
					printf("Elemento %d empilhado.\n", valor);
			} else {
					while (getchar() != '\n'); 
					printf("Entrada inválida.\n");
				}
				break;
				
			case 2:
			p = desempilha(p, &e_retirado);
				if (e_retirado != -1) {
					printf("Elemento %d desempilhado do topo.\n", e_retirado);
				} 
			break;
				
			case 3:
			imprimePilha(p);
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
