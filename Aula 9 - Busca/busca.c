#include <stdio.h>
#include <stbilio.h>
#define TAM 10

/*inserir*/
int inserir(int )
/*buscar sequencial*/
int buscaSeq(int *vet, int tam, int valor);

/*buscar binaria*/
int buscaBin(int *vet, int inicio, int fim, int valor);

int buscaSeq(int *vet, int tam, int valor){
    
    int i;
    int pos = -1;
    
    for (i=0, i<tam; i++){
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
    
    Lista busca[TAM];
    int opcao, valor;
    
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
                printf("Digite o valor inteiro a ser inserido: ");
                scanf("%d", &valor);
                
                printf("Elemento %d inserido.\n", valor);
                break;

            case 2:
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &valor);
                buscaSeq(busca);
                if (encontrado != NULL) {
                    printf("Elemento %d encontrado\n", valor);
                } else {
                    printf("Valor %d não encontrado.\n", valor);
                }
                break;

            case 3:
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &valor);
                buscaBin(busca);
                if (encontrado != NULL) {
                    printf("Elemento %d encontrado na posiçao [%d]
                            \n", valor pos);
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