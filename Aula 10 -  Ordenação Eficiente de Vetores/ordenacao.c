#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 10

int Lista[TAM_MAX];
void criaLista(int *Lista);
void inserir(int vet[]);
void bubbleSort(int *vet, int n);



void inserir(int vet[])

    int i,valor;
    for (i=0; i < TAM_MAX; i++ ){
        printf("Valor inserido: ");
        scanf("%d", &valor);
        vet[i] = valor;
    }
}

void bubbleSort(int *vet, int n){
    int i, j, trocou, aux;
    j=1;
    trocou=1; 
    while ((j<n) && trocou){
        trocou=0; 
        for(i=0; i<(n-j); i++){
            if(vet[i]>vet[i+1]){
                aux= vet[i];
                vet[i]=vet[i+1];
                vet[i+1]=aux;
                trocou=1; 
            }
        }
        j++;
    }
}

int main(){
    
    int busca[TAM_MAX];
    int opcao, valor, pos;
    
    do {
        printf("\n----- MENU DE OPÇÕES -----\n");
        printf("1 - Inserir elemento\n");
        printf("2 - Buscar um elemento (Busca sequencial)\n");
        printf("3 - Buscar um elemento (Busca binaria)\n");
        printf("0 - Sair\n");
        printf("Escolha a opção: ");

        if (scanf("%d", &opcao) != 1) {
             while (getchar() != '\n');
             opcao = -1;
        }

        switch (opcao) {
            case 1:
                inserir(busca);
                break;

            case 2:
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &valor);
                pos = buscaSeq(busca, valor);
                
                if (pos != -1) {
                    printf("Valor encontrado na posiçao [%d]\n", pos);
                } else {
                    printf("Valor %d não encontrado.\n", valor);
                }
                break;

            case 3:
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &valor);
                pos = buscaBin(busca,0, TAM_MAX, valor);
                if (pos != -1) {
                    printf("Elemento encontrado na posiçao [%d]\n", pos);
                } else {
                    printf("Valor %d não encontrado.\n", valor);
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