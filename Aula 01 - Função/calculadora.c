#include <stdio.h>

float soma(float num1, float num2) 
{
    return num1 + num2;
}

float produto(float num1, float num2) 
{
    return num1 * num2;
}

float diferenca(float num1, float num2) 
{
    return num1 - num2;
}

float divisao(float num1, float num2) 
{
    if (num2 == 0) {
        printf("Erro: Divisão por zero!\n");
        return 0;
    }
    return num1 / num2;
}

float calculo(float num1, float num2, char opcao)
{
    switch (opcao)
    {
        case '+':
            return soma(num1, num2);
        case '*':
            return produto(num1, num2);
        case '-':
            return diferenca(num1, num2);
        case '/':
            return divisao(num1, num2);
        default:
            printf("Operação inválida!\n");
            return 0;
    }
}
int main(void)
{
    float a, b, resultado;
    char opcao;
    
    printf("Informe o primeiro valor: ");
    scanf("%f", &a);
    printf("Informe o segundo valor: ");
    scanf("%f", &b);
    
    printf("Informe qual operação deseja fazer (+, -, *, /): ");
    scanf(" %c", &opcao);  // Espaço antes do %c para ignorar whitespace
    
    resultado = calculo(a, b, opcao);
    printf("Resultado = %.2f\n", resultado);
    
    return 0;
}
