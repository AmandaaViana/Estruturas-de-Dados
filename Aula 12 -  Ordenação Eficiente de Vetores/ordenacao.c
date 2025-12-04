#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 10

void inserir(int vet[]);
void merge(int *vet, int *aux, int esq, int meio, int dir);
void mergeSort(int *vet, int *aux, int esq, int dir); //divisão do vetor em vetores menores
void imprimeVetor(int vet[]);

void inserir(int vet[]){
    int i,valor;
    
    for (i=0; i < TAM_MAX; i++ ){
        printf("Valor inserido:");
        scanf("%d", &valor);
        vet[i] = valor;
    }
}

void merge(int *vet, int *aux, int esq, int meio, int dir){
    int l1, l2, i;
    
    for (l1 = esq, l2 = meio + 1, i = esq; l1 <= meio && l2 <= dir; i++){
        if (vet[l1] <= vet[l2])
            aux[i] = vet[l1++];
        else
           aux[i] = vet[l2++]; 
    }
    while(l1 <= meio)
        aux[i++] = vet[l1++];
        
    while(l2 <= dir)
        aux[i++] = vet[l2++];
        
    for (i = esq; i <= dir; i++)
        vet[i] = aux[i];
}

void mergeSort(int *vet, int *aux, int esq, int dir){
    int meio;
    
    if(esq < dir){
        meio = (esq + dir) /2;
        mergeSort(vet, aux, esq, meio);
        mergeSort(vet, aux, meio + 1 , dir);
        merge(vet, aux, esq, meio, dir);
    } else {
        return;
    }
}

void imprimeVetor(int vet[]){
    int i;
    printf("Vetor: [");
    for (i = 0; i < TAM_MAX; i++) {
        printf("%d", vet[i]);
        if (i < TAM_MAX - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main(){
    
    int ordenacao[TAM_MAX];
    int aux[TAM_MAX];
    int opcao;
    
    do {
        printf("\n----- MENU DE OPÇÕES -----\n");
        printf("1 - Inserir elemento\n");
        printf("2 - Visualizar vetor atual\n");
        printf("3 - Odenanar elementos\n");
        printf("0 - Sair\n");
        printf("Escolha a opção: ");

        if (scanf("%d", &opcao) != 1) {
             while (getchar() != '\n');
             opcao = -1;
        }

        switch (opcao) {
            case 1:
                inserir(ordenacao);
                break;

            case 2:
                imprimeVetor(ordenacao);
                break;

            case 3:
                mergeSort(ordenacao, aux, 0, TAM_MAX - 1); 
                imprimeVetor(ordenacao);
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
