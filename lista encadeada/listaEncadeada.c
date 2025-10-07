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

#define MaxItens 10

struct elementstruct elemento {
	int conteudo;
	int prox; 
}
struct tpLista {
	struct elemento e[MaxItens]; 
	int inicio; 
}

struct elemento{
	int dado;
	struct elemento *prox;
	}

typedef struct elemento Nodo;


void Lista criarLista(){
	
	}

void imprimeLista(Lista l){
		Lista p;
		printf("Itens da Lista");
		p = l;
		while (p != NULL){ //enquanto nao chega ao final
			printf("%d - ",p->dado); //imprime o elemento
			p = p->prox; //avança para o proximo
			}
		printf("\n");
		}

int insereLista(){}

ListaretiraLista(){
	Lista p, ant;
	
	p=l;
	ant=l;
	while((p != NULL) && (p-> !=e)){
		ant = p;
		p = p->prox;
		}
	if (p != NULL){ //encontrou o elemento, remove
		if (p == ant){ //remove primeiro
			l = p->prox;
			free (p);
			}
		else { //nao é o primeiro 
			ant->prox = p->prox;
			free(p);
			}
		}
		return(l);
	}

Lista buscarElemento(Lista l, int e){
	Lista p;
	
	p = l;
	while((p != NULL) && (p-> !=e)){
		p = p->prox;
		}
	return (p);//retorna o endereço ou NULL
	}


int contaLista(Lista l){//número de elementos da lista
	Lista p;
	int cont = 0;
	
	p = l;
	while (p != NULL){
		cont++;
		p = p->prox;
		}
	return cont;
}

//menu
int main(){
 
	int opçao;
	
	
	
	

	return 0;
}

