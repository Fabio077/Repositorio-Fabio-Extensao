#include <stdio.h>
#include <stdlib.h>

int soma(int a, int b) {
    return a + b;
}

int multiplicacao(int a, int b) {
    return a * b;
}

void mostrar_matriz(int **matriz, int n, char nome) {
    printf("\nMatriz %c:\n", nome);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n = 2; // tamanho da matriz

    // Aloca matriz A
    int **A = malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++)
        A[i] = malloc(n * sizeof(int));

    // Inicializa matriz A
    A[0][0] = 1; A[0][1] = 2;
    A[1][0] = 3; A[1][1] = 4;

    // Aloca matriz B
    int **B = malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++)
        B[i] = malloc(n * sizeof(int));

    // Inicializa matriz B
    B[0][0] = 5; B[0][1] = 6;
    B[1][0] = 7; B[1][1] = 8;

    // Aloca matriz resultado
    int **resultado = malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++)
        resultado[i] = malloc(n * sizeof(int));

    mostrar_matriz(A, n, 'A');
    mostrar_matriz(B, n, 'B');

    printf("\n--- Passo a passo da multiplicacao ---\n");
    // Multiplicacao
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int soma_total = 0;
            printf("Resultado[%d][%d] = ", i, j);
            for(int k = 0; k < n; k++) {
                int mult = multiplicacao(A[i][k], B[k][j]);
                soma_total = soma(soma_total, mult);
                printf("%d*%d", A[i][k], B[k][j]);
                if (k < n - 1)
                    printf(" + ");
            }
            resultado[i][j] = soma_total;
            printf(" = %d\n", soma_total);
        }
    }

    mostrar_matriz(resultado, n, 'R');

    // Libera memória
    for(int i = 0; i < n; i++) {
        free(A[i]);
        free(B[i]);
        free(resultado[i]);
    }
    free(A);
    free(B);
    free(resultado);

    return 0;
}
