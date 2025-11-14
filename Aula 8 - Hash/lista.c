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
