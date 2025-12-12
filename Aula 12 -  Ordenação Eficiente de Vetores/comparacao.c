#include <stdio.h>
#include <stdlib.h>
#include <time.h>   
#include <string.h> 

void troca(int *a, int *b); 
void preencherVetor(int *vet, int n);
void clonarVetor(int *origem, int *destino, int n);
void bubbleSort(int *vet, int n);
void merge(int *vet, int *aux, int esq, int meio, int dir);
void mergeSort(int *vet, int *aux, int esq, int dir); 
int particione(int a[], int p, int r);
void quicksort(int a[], int p, int r);

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void preencherVetor(int *vet, int n) {
    srand(time(NULL)); 
    for (int i = 0; i < n; i++) {
        vet[i] = rand() % 100000; 
    }
}

void clonarVetor(int *origem, int *destino, int n) {
    memcpy(destino, origem, n * sizeof(int));
}

void bubbleSort(int *vet, int n){
    int i, j, trocou, temp;
    j=1;
    trocou=1;  
    while ((j<n) && trocou){
        trocou=0; 
        for(i=0; i<(n-j); i++){
            if(vet[i]>vet[i+1]){
                temp = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = temp;
                trocou=1;
            }
        }
        j++;
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
        meio = (esq + dir) / 2;
        mergeSort(vet, aux, esq, meio);
        mergeSort(vet, aux, meio + 1 , dir);
        merge(vet, aux, esq, meio, dir);
    } 
}

int particione(int a[], int p, int r){
    int pivot = a[r]; 
    int i = p - 1;

    for (int j = p; j <= r - 1; j++) {
        if (a[j] < pivot) {
            i++; 
            troca(&a[i], &a[j]); 
        }
    }
    troca(&a[i + 1], &a[r]);
    return (i + 1);
}

void quicksort(int a[], int p, int r){
    if (p < r) {
        int i = particione(a, p, r);
        quicksort(a, p, i-1);
        quicksort(a, i+1, r);
    }
}

int main(){
    int N; 
    int *vetorOriginal = NULL;
    int *vetorTeste = NULL;
    int *auxiliarMerge = NULL;
    
    time_t inicio, fim;   
    double tempoExecucao;

    printf("--- COMPARATIVO DE ALGORITMOS DE ORDENAÇÃO ---\n");
    printf("Digite o tamanho do vetor (N): ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("Tamanho inválido ou N não é positivo. Encerrando.\n");
        return 1;
    }

    vetorOriginal = (int *)malloc(N * sizeof(int));
    vetorTeste = (int *)malloc(N * sizeof(int));
    auxiliarMerge = (int *)malloc(N * sizeof(int));
    
    if (vetorOriginal == NULL || vetorTeste == NULL || auxiliarMerge == NULL) {
        printf("Erro ao alocar memória. Tente um tamanho menor para N.\n");
        free(vetorOriginal);
        free(vetorTeste);
        free(auxiliarMerge);
        return 1;
    }

    //preenche apenas uma vez
    preencherVetor(vetorOriginal, N);
    printf("\nAlocando a memoria...\n");

    //BUBBLESORT
    clonarVetor(vetorOriginal, vetorTeste, N);
    time(&inicio);// tempo de inicial
    bubbleSort(vetorTeste, N);
    time(&fim);// tempo final
    tempoExecucao = difftime(fim, inicio); // calcula a diferença
    printf("\n[RESULTADO] BubbleSort (N=%d): %.0f segundos\n", N, tempoExecucao);
    

    
    //MERGE SORT
    clonarVetor(vetorOriginal, vetorTeste, N);
    time(&inicio);
    mergeSort(vetorTeste, auxiliarMerge, 0, N - 1);
    time(&fim);
    tempoExecucao = difftime(fim, inicio);
    printf("[RESULTADO] MergeSort (N=%d): %.0f segundos\n", N, tempoExecucao);
   
    //QUICK SORT
    clonarVetor(vetorOriginal, vetorTeste, N);
    time(&inicio);
    quicksort(vetorTeste, 0, N - 1);
    time(&fim);
    tempoExecucao = difftime(fim, inicio);
    printf("[RESULTADO] QuickSort (N=%d): %.0f segundos\n", N, tempoExecucao);

    //libera memória
    free(vetorOriginal);
    free(vetorTeste);
    free(auxiliarMerge);
    
    printf("\nComparativo finalizado.\n");

    return 0;
}
