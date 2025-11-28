#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 10

int Lista[TAM_MAX];
void criaLista(int *Lista);
void inserir(int vet[]);
int buscaSeq(int *vet, int valor);
int buscaBin(int *vet, int inicio, int fim, int valor);


void inserir(int vet[]){
    int i,j,valor;
    
    for (i=0; i < TAM_MAX; i++ ){
        printf("Valor inserido:(em ordem)");
        scanf("%d", &valor);
        vet[i] = valor;
    }
}

int buscaSeq(int *vet, int valor){
    
    int i;
    int pos = -1;
    
    for (i=0; i<TAM_MAX; i++){
        if (valor == vet[i])
        pos = i;
    }
    return (pos);
}

int buscaBin(int *vet, int inicio, int fim, int valor){
    int meio;
    int pos = -1;
    
    if (inicio > fim)
        pos = -1;
    else{
        meio = (inicio + fim) / 2;
        if (valor == vet[meio])
        pos = meio;
        else if (valor > vet[meio])
            pos = buscaBin(vet, meio+1, fim, valor);
        else
            pos = buscaBin(vet, inicio, meio-1, valor);
    }
    return (pos);
}

int main(){
    
    int busca[TAM_MAX];
    int opcao, valor, pos;
    
    do {
        printf("\n----- MENU DE OPÇÕES -----\n");
        printf("1 - Inserir elemento\n");
        printf("2 - Buscar um elemento. Busca sequencial\n");
        printf("3 - Buscar um elemento. Busca binaria\n");
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
                    printf("Valor encontrado na posiçao %d\n", pos);
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
