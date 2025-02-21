#include <stdio.h>

#define TAMANHO 10  
#define TAM_NAVIO 3 

int main() {
    int tabuleiro[TAMANHO][TAMANHO] = {0}; 

    int linha_h = 2, coluna_h = 4; 
    int linha_v = 5, coluna_v = 6; 

    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha_h][coluna_h + i] = 3;
    }

    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha_v + i][coluna_v] = 3;
    }

    printf("\nTabuleiro de Batalha Naval:\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
