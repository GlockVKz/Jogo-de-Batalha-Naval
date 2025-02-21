#include <stdio.h>

#define TAMANHO 10  
#define TAM_NAVIO 3 
#define AGUA 0
#define NAVIO 3


int pode_posicionar(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linha, c = coluna;

        if (diagonal == 0) { 
            if (direcao == 0) c += i; 
            else l += i;  
        } else { 
            if (diagonal == 1) { 
                l += i;
                c += i;
            } else { 
                l += i;
                c -= i;
            }
        }

        if (l >= TAMANHO || c < 0 || c >= TAMANHO || tabuleiro[l][c] != AGUA) return 0;
    }
    return 1;
}

void posicionar_navio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linha, c = coluna;

        if (diagonal == 0) {
            if (direcao == 0) c += i;
            else l += i;
        } else {
            if (diagonal == 1) {
                l += i;
                c += i;
            } else {
                l += i;
                c -= i;
            }
        }

        tabuleiro[l][c] = NAVIO;
    }
}

void exibir_tabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("\nTabuleiro de Batalha Naval:\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO] = {0}; 

    int navios[4][3] = {
        {1, 1, 0}, 
        {4, 6, 1}, 
        {2, 2, 1}, 
        {6, 8, 2}  
    };

    for (int i = 0; i < 4; i++) {
        int linha = navios[i][0], coluna = navios[i][1];
        int direcao = (i < 2) ? navios[i][2] : 0;
        int diagonal = (i >= 2) ? navios[i][2] : 0;

        if (pode_posicionar(tabuleiro, linha, coluna, direcao, diagonal)) {
            posicionar_navio(tabuleiro, linha, coluna, direcao, diagonal);
        }
    }


    exibir_tabuleiro(tabuleiro);

    return 0;
}
