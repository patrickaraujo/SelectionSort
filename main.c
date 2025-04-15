#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int *V, int N) {
    int i, j, menor, troca;
    for (i = 0; i < N - 1; i++) {
        menor = i;
        for (j = i + 1; j < N; j++) {
            if (V[j] < V[menor])
                menor = j;
        }
        if (i != menor) {
            troca = V[i];
            V[i] = V[menor];
            V[menor] = troca;
        }
    }
}

void imprimirVetor(int *v, int N) {
    for (int i = 0; i < N; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    int tamanho;
    
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);
    
    int *vetor = (int *)malloc(tamanho * sizeof(int));
    
    if (vetor == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }
    
    // Preenche o vetor com valores aleatórios
    srand(time(NULL));
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 100; // Números entre 0 e 99
    }
    
    printf("Vetor antes da ordenacao:\n");
    imprimirVetor(vetor, tamanho);
    
    selectionSort(vetor, tamanho);
    
    printf("Vetor depois da ordenacao:\n");
    imprimirVetor(vetor, tamanho);
    
    free(vetor);
    
    return 0;
}
