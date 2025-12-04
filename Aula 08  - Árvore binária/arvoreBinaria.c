#include <stdio.h>
#include <stdlib.h>

struct Elemento {
 int dado;
 struct Elemento *esq;
 struct Elemento *dir;
};
typedef struct Elemento *Arvore;


Arvore criaArvore();
void insereArvore(Arvore *a, int valor);
void retiraArvore(Arvore *a, int valor);
void antecessor(Arvore a, Arvore *x);
Arvore buscaArvore(Arvore a, int valor);
void preOrdem(Arvore a);
void inOrdemCre(Arvore a);
void posOrdem(Arvore a);

Arvore criaArvore(){
 return NULL;
}
void insereArvore(Arvore *a, int valor){
    if ((*a) == NULL){ 
        (*a) = (Arvore)malloc(sizeof(struct Elemento));
        (*a) -> dado = valor;
        (*a) -> esq = NULL;
        (*a) -> dir = NULL;
    }  
    else if (valor < (*a) -> dado) 
        insereArvore(&((*a) -> esq), valor);
    else if (valor > (*a) -> dado) 
        insereArvore(&((*a) -> dir), valor);
    else
        printf("\nValor ja existe... tente outro.\n");
}
void retiraArvore(Arvore *a, int valor) {
     Arvore aux;
    
     if (*a != NULL) { 
       if (valor > ((*a)->dado)) { 
        retiraArvore(&((*a)->dir), valor);
       } else if (valor < ((*a)->dado)) { 
           retiraArvore(&((*a)->esq), valor);
       } else { 
          if ((*a)->dir == NULL) { 
             aux = (*a);
             *a = aux->esq;
             free(aux);
          } else if ((*a)->esq == NULL) { 
               aux = (*a)->dir;
               free(*a);
               *a = aux;
           } else { 
               antecessor(*a, &((*a)->esq)); 
             }
       }
     }
}
void antecessor(Arvore a, Arvore *x) {
     Arvore aux;

     if ((*x)->dir != NULL) {
      antecessor(a, &((*x)->dir));
     } else {
      a->dado = (*x)->dado;
      aux = *x;
      *x = aux->esq;
      free(aux);
      }
}

Arvore buscaArvore(Arvore a, int valor){
    if (a == NULL){ 
    return NULL;
    }
    else if (valor < a -> dado) 
        return buscaArvore(a -> esq, valor);
    else if (valor > a -> dado)
        return buscaArvore(a -> dir, valor);
    else 
        return a;
}
void preOrdem(Arvore a){
    if (a != NULL) {
        printf("\n%d", a->dado);
        preOrdem(a->esq);
        preOrdem(a->dir);
    }
}
void inOrdemCre(Arvore a){ 
    if (a != NULL) {
        inOrdemCre(a->esq);
        printf("\n%d", a->dado);
        inOrdemCre(a->dir);
    }
}
void posOrdem(Arvore a){
    if (a != NULL) {
        posOrdem(a->esq);
        posOrdem(a->dir);
        printf("\n%d", a->dado);
    }
}


int main() {
    Arvore minhaArvore;
    int valor, opcao;
    Arvore encontrado;

    minhaArvore = criaArvore(); 

    do {
        printf("\n----- MENU DE OPÇÕES -----\n");
        printf("1 - Inserir um elemento na árvore\n");
        printf("2 - Retirar um elemento da árvore\n");
        printf("3 - Buscar um elemento na árvore\n");
        printf("4 - Imprimir todos os elementos da árvore em pré-ordem\n");
        printf("5 - Imprimir todos os elementos da árvore em ordem crescente\n");
        printf("6 - Imprimir todos os elementos da árvore em pós-ordem\n");
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
                insereArvore(&minhaArvore, valor); 
                break;

            case 2:
                printf("Digite o valor a ser retirado: ");
                scanf("%d", &valor);
                retiraArvore(&minhaArvore, valor);
                break;

            case 3:
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &valor);
                encontrado = buscaArvore(minhaArvore, valor);
                if (encontrado != NULL) {
                    printf("Elemento %d encontrado no endereço: %p\n", valor, (void *)encontrado);
                } else {
                    printf("Elemento %d não encontrado!\n", valor);
                }
                break;

            case 4:
                printf("\nPercurso Pré-Ordem: ");
                preOrdem(minhaArvore);
                break;

            case 5:
                printf("\nPercurso Em Ordem (Crescente): ");
                inOrdemCre(&minhaArvore);
                break;
            case 6:
                printf("\nPercurso Pós-Ordem: ");
                posOrdem(&minhaArvore);
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
