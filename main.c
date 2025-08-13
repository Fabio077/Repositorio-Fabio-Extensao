#include <stdio.h>

int main() {
    float num1, num2, resultado;
    char operacao;

    while (1) {
        printf("\nDigite a operação (+, -, *, /) ou 'q' para sair: ");
        scanf(" %c", &operacao);

        if (operacao == 'q' || operacao == 'Q') {
            printf("Encerrando a calculadora...\n");
            break;
        }

        printf("Digite o primeiro número: ");
        scanf("%f", &num1);
        printf("Digite o segundo número: ");
        scanf("%f", &num2);

        switch (operacao) {
            case '+':
                resultado = num1 + num2;
                printf("Resultado: %.2f\n", resultado);
                break;
            case '-':
                resultado = num1 - num2;
                printf("Resultado: %.2f\n", resultado);
                break;
            case '*':
                resultado = num1 * num2;
                printf("Resultado: %.2f\n", resultado);
                break;
            case '/':
                if (num2 != 0) {
                    resultado = num1 / num2;
                    printf("Resultado: %.2f\n", resultado);
                } else {
                    printf("Erro: divisão por zero!\n");
                }
                break;
            default:
                printf("Operação inválida!\n");
        }
    }

    return 0;
}
