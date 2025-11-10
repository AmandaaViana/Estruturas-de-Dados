#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct aluno {
    char nome[40];
    int matricula;
    float prova1;
    float prova2;
    float media;
    int faltas;
    char situacao[15]; // "Aprovado" ou "Reprovado"
};

struct turma {
    struct aluno cadastro[40];
    int cont;
};

struct turma c;

// Le string de forma segura 
void leString(char *s, int tam)
{
    if (fgets(s, tam, stdin) == NULL) {
        s[0] = '\0';
        return;
    }
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    } else {
        if (len == (size_t)(tam - 1)) {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
        }
    }
}

struct aluno leAluno()
{
    struct aluno a;
    char buffer[100];

    printf("\nNome: ");
    leString(a.nome, sizeof(a.nome));

    printf("Matricula: ");
    leString(buffer, sizeof(buffer));
    a.matricula = atoi(buffer);

    printf("Nota da prova 1: ");
    leString(buffer, sizeof(buffer));
    a.prova1 = atof(buffer);

    printf("Nota da prova 2: ");
    leString(buffer, sizeof(buffer));
    a.prova2 = atof(buffer);

    printf("Numero de faltas: ");
    leString(buffer, sizeof(buffer));
    a.faltas = atoi(buffer);

    // Calcula media
    a.media = (a.prova1 + a.prova2) / 2.0;

    // Define situaçao
    if (a.media >= 6.0 && a.faltas <= 20) {
        strcpy(a.situacao, "Aprovado");
    } else {
        strcpy(a.situacao, "Reprovado");
    }

    return a;
}

int salvaCadastro(int n)
{
    FILE *arq = fopen("alunos.dat", "wb");
    if (arq == NULL) {
        fprintf(stderr, "\nErro ao abrir arquivo para escrita\n");
        return 1;
    }
    size_t written = fwrite(c.cadastro, sizeof(struct aluno), (size_t)n, arq);
    fclose(arq);
    return (written == (size_t)n) ? 0 : 1;
}

int leCadastro()
{
    char buffer[100];
    char continua;
    int i = 0;

    do {
        if (i >= 40) {
            printf("Turma cheia (40 alunos).\n");
            break;
        }
        c.cadastro[i] = leAluno();
        i++;

        printf("\nJa foram lidos %d aluno(s). Deseja continuar (s/n): ", i);
        leString(buffer, sizeof(buffer));
        continua = (buffer[0] == '\0') ? 'n' : buffer[0];
        if (continua >= 'A' && continua <= 'Z') continua = continua - 'A' + 'a';
    } while (continua == 's');

    c.cont = i;
    return i;
}

int carregaCadastro()
{
    FILE *arq = fopen("alunos.dat", "rb");
    if (arq == NULL) {
        fprintf(stderr, "\nErro ao abrir arquivo para leitura\n");
        return -1;
    }
    int j = 0;
    while (j < 50 && fread(&c.cadastro[j], sizeof(struct aluno), 1, arq) == 1) {
        j++;
    }
    fclose(arq);
    c.cont = j;
    return j;
}

void listaCadastro(int n)
{
    if (n <= 0) {
        printf("\nNenhum aluno cadastrado.\n");
        return;
    }
    for (int j = 0; j < n; j++) {
        printf("\nMatricula: %d\nNome: %s\n", c.cadastro[j].matricula, c.cadastro[j].nome);
        printf("Prova 1: %.2f | Prova 2: %.2f | Media: %.2f\n",
               c.cadastro[j].prova1, c.cadastro[j].prova2, c.cadastro[j].media);
        printf("Faltas: %d | Situaçao: %s\n", c.cadastro[j].faltas, c.cadastro[j].situacao);
        printf("-----------------------------------------\n");
    }
}

int menu()
{
    int op;
    char str[10];

    do {
        printf("\n1 - Carregar Cadastro de Alunos");
        printf("\n2 - Cadastrar Alunos");
        printf("\n3 - Salvar Cadastro de Alunos");
        printf("\n4 - Listar Cadastro de Alunos");
        printf("\n0 - Encerrar");
        printf("\n\nEscolha uma opçao: ");
        leString(str, sizeof(str));
        sscanf(str, "%d", &op);
    } while ((op < 0) || (op > 4));
    return op;
}

int main(void)
{
    int numAlunos = 0;
    int codigo = 0;
    int opcao;

    do {
        opcao = menu();
        switch (opcao) {
            case 1: {
                int l = carregaCadastro();
                if (l >= 0) {
                    numAlunos = l;
                    printf("\nNumero de Alunos = %d\n", numAlunos);
                } else {
                    printf("\nErro ao carregar o arquivo.\n");
                }
                break;
            }
            case 2:
                numAlunos = leCadastro();
                break;
            case 3:
                codigo = salvaCadastro(numAlunos);
                if (codigo == 0)
                    printf("\nCadastro salvo com sucesso\n");
                else
                    printf("\nErro ao salvar cadastro\n");
                break;
            case 4:
                listaCadastro(numAlunos);
                break;
        }
    } while (opcao != 0);

    return 0;
}
