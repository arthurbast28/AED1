#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("Digite quantos números você quer armazenar: ");
    scanf("%d", &n);

    // Aloca memória dinamicamente para um vetor de n inteiros
    int *vetor = (int *)malloc(n * sizeof(int));

    if (vetor == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        return 1;
    }

    // Preenche o vetor
    for (int i = 0; i < n; i++) {
        vetor[i] = i * 10;
    }

    // Imprime o vetor
    printf("Valores no vetor:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // Libera a memória alocada
    free(vetor);

    return 0;
}
