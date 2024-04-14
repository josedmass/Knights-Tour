#include <stdio.h>
#include <stdlib.h>
#include "passeio.h"

int main() {
    int x, y; // posições iniciais do cavalo
    printf("Digite as posicoes do cavalo (linha, coluna): ");
    scanf("%d %d", &x, &y);

    // Fazendo o passeio do cavalo a partir das posições fornecidas
    passeio(x, y);

    return 0;
}