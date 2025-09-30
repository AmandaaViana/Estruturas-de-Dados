#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxItens 10
#define TamItem 20

typedef char tpLista[MaxItens][TamItem];

void insereLista(tpLista l, char *item)
void retiraLista(tpLista l, char *item)
void criarLista(tpLista l)
int contaLista(tpLista l)
void imprimeLista(tpLista l)

void insereLista(tpLista l, char *item){
	int i;
	for(i=0; i<MaxItens && strlen(l[i])>0; i++);
	if (i<MaxItens){
		strcpy(l[i],item);
		printf("\nItem (%s) inserido com sucesso",item);
	}
	else 
		printf("\nLista cheia, não pode inserir");
	}
	
void retiraLista(tpLista l, char *item)
{
	int i;
	for(i=0; i<MaxItens && strlen(l[i])>0 && (strcmp(l[i],item) != 0); i++);
	if (i<MaxItens && (strcmp(l[i],item) == 0)){ 
		printf("\nItem (%s) encontrado, removendo",item);
		if (i < (MaxItens-1)){ 
			for (;i<(MaxItens-1) && strlen(l[i])>0;i++)
				strcpy(l[i],l[i+1]);
			}
			l[MaxItens-1][0] = '\0';
	}
	else
		printf("\nItem (%s) não encontrado",item);
}
	
void criarLista(tpLista l)
{
	int i;
	for (i=0; i<MaxItens;i++)
	l[i][0] = '\0';
}
	
int contaLista(tpLista l)
{
	int i;
	for(i = 0; i<MaxItens && strlen(l[i])>0; i++);
	if(i<MaxItens){
		strcpy(l[i],item);
		printf("\nItem (%s) inserido com sucesso",item)
		}
		else 
			printf("\nLista cheia, não pode inserir");
	return(i);
}

void imprimeLista(tpLista l)
{
	int i;
	printf("\n Itens da lista\n");
	for(i=0; i<MaxItens && strlen(l[i])>0; i++);
		printf("\n%s",l[i]);
	printf("\n");
}

//menu
int main()
{
	
	int opcao;
	
	do{
		printf("1 - Inserir elemento");
		printf("2 - Retirar Elemento");
		printf("3 - Criar Lista");
		printf("4 - Contar elementos da lista");
		printf("5 - Exibir o conteúdo da lista");
		printf("0 - sair");
		scanf("%d", &opcao);
		
		switch (opcao)
			case 1:
			printf("Informe o elemento desejado: ");
			insereLista(tpLista l, char *item);
			break
			case 2:
			printf("Informe o elemento que deseja retirar: ");
			retiraLista(tpLista l, char *item);
			break
			case 3:
			printf("Informe o elemento que deseja retirar: ");
			criarLista(tpLista l);
			break
			case 4:
			printf("Informe o elemento que deseja retirar: ");
			contaLista(tpLista l);
			break
			case 5:
			imprimeLista(tpLista l)
			break
			
		}while(opçao != 0);
	return 0;
}

