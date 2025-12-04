#include <stdio.h>
#include <stdlib.h>



void bubbleSort(int *vet, int n);
void merge(int *vet, int *aux, int esq, int meio, int dir);
void mergeSort(int *vet, int *aux, int esq, int dir); 
int particione(int a[], int p, int r);
void quicksort(int a[], int p, int r);

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

int particione(int a[], int p, int r){
    int i = p-1, j = r;
    int v = a[r];
 
    for (;;) {
        while (a[++i] < v) ;
        while (v < a[--j])
        if (/*X*/ j == p) break;
        if (i >= j) break;
        troca(a[i], a[j]);
    }
    troca(a[i], a[r]);
    return i;
}

void quicksort(int a[], int p, int r){
    int i;
    if (p < r) {
        i = particione(a, p, r);
        quicksort(a, p, i-1);
        quicksort(a, i+1, r);
    }
}


int main()
{
    printf("Hello World");

    return 0;
}