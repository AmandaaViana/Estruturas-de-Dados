#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxItems 10
#define TamItem 20

typedef char tplista[MaxItems][TamItem];

void criaLista(tplista l);
void insereLista(tplista l, char *item);
void retiraLista(tplista l, char *item);
int contaLista(tplista l);
void imprimeLista(tplista l);
void limparBuffer();

void criaLista(tplista l) {
    int i;
    for (i = 0; i < MaxItems; i++) {
        l[i][0] = '\0';
    }
    printf("Nova lista criada/limpa com sucesso!\n\n");
}

void insereLista(tplista l, char *item) {
    int i;
    
    if (strlen(item) == 0) {
        printf("Erro: Não é possível inserir string vazia!\n");
        return;
    }
    if (strlen(item) >= TamItem) {
        printf("Erro: String muito longa! Máximo de %d caracteres.\n", TamItem - 1);
        return;
    }
    for (i = 0; i < MaxItems && strlen(l[i]) > 0; i++);
    if (i < MaxItems) {
        strcpy(l[i], item); 
        printf("Item '%s' inserido com sucesso na posição %d!\n", item, i + 1);
    } else {
        printf("Lista cheia! Não é possível inserir '%s'.\n", item);
    }
}

void retiraLista(tplista l, char *item) {
    int i, j;
    
    for (i = 0; i < MaxItems && strlen(l[i]) > 0 && (strcmp(l[i], item) != 0); i++);
    if (i < MaxItems && strlen(l[i]) > 0 && (strcmp(l[i], item) == 0)) {
        printf("Item '%s' encontrado na posição %d, removendo...\n", item, i + 1);
        
        if (i < (MaxItems - 1)) {
            
            for (j = i; j < (MaxItems - 1) && strlen(l[j]) > 0; j++) {
                strcpy(l[j], l[j + 1]);
            }
        }
        l[MaxItems - 1][0] = '\0';
        printf("Item removido com sucesso!\n");
    } else {
        printf("Item '%s' não encontrado na lista.\n", item);
    }
}

int contaLista(tplista l) {
    int i;
    for (i = 0; i < MaxItems && strlen(l[i]) > 0; i++);
    return i;
}

void imprimeLista(tplista l) {
    int i;
    int total = contaLista(l);
    
    if (total == 0) {
        printf("Lista vazia!\n");
        return;
    }
    
    printf("\nCONTEÚDO DA LISTA\n");
    for (i = 0; i < MaxItems && strlen(l[i]) > 0; i++) {
        printf("%d: %s\n", i + 1, l[i]);
    }
    printf("Total de elementos: %d\n", total);
    printf("Capacidade máxima: %d elementos\n", MaxItems);
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// PRINCIPAL
int main() {
    tplista lista;
    int opcao;
    char elemento[TamItem];
    
    criaLista(lista);
    
    printf("SISTEMA DE LISTA\n");
    printf("Implementação com vetor de strings\n");
    printf("Capacidade: %d elementos de até %d caracteres cada\n\n", MaxItems, TamItem - 1);
    
    do {
        printf("1. Inserir elemento\n");
        printf("2. Retirar elemento\n");
        printf("3. Criar/limpar lista\n");
        printf("4. Contar elementos da lista\n");
        printf("5. Exibir conteúdo da lista\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        
        scanf("%d", &opcao);
        limparBuffer(); 
        
        switch (opcao) {
            case 1: 
                printf("Digite o elemento a ser inserido: ");
                fgets(elemento, sizeof(elemento), stdin);
                elemento[strcspn(elemento, "\n")] = '\0';
                insereLista(lista, elemento);
                break;
                
            case 2:  
                if (contaLista(lista) == 0) {
                    printf("Lista vazia! Não há elementos para remover.\n");
                } else {
                    printf("Digite o elemento a ser removido: ");
                    fgets(elemento, sizeof(elemento), stdin);
                    elemento[strcspn(elemento, "\n")] = '\0';
                    retiraLista(lista, elemento);
                }
                break;
                
            case 3: 
                criaLista(lista);
                break;
                
            case 4:  
                printf("Total de elementos na lista: %d\n", contaLista(lista));
                break;
                
            case 5:  
                imprimeLista(lista);
                break;
                
            case 0:  
                printf("Encerrando o programa...\n");
                break;
                
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
        
    } while (opcao != 0);
    
    return 0;
}