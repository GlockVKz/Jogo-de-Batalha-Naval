#include <stdio.h>

#define TAMANHO 10  
#define TAM_NAVIO 3 
#define NAVIO 3
#define AGUA 0
#define HABILIDADE 5


void inicializar_tabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++)
        for (int j = 0; j < TAMANHO; j++)
            tabuleiro[i][j] = AGUA;
}


void exibir_tabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("\nTabuleiro de Batalha Naval:\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            if (tabuleiro[i][j] == NAVIO) printf("3 ");
            else if (tabuleiro[i][j] == HABILIDADE) printf("5 ");
            else printf("0 ");
        }
        printf("\n");
    }
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

        if (l < TAMANHO && c >= 0 && c < TAMANHO) tabuleiro[l][c] = NAVIO;
    }
}


void aplicar_habilidade(int tabuleiro[TAMANHO][TAMANHO], int matriz[5][5], int linha, int coluna) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int l = linha + i - 2, c = coluna + j - 2;
            if (l >= 0 && l < TAMANHO && c >= 0 && c < TAMANHO && matriz[i][j] == 1 && tabuleiro[l][c] != NAVIO)
                tabuleiro[l][c] = HABILIDADE;
        }
    }
}


void matriz_cone(int matriz[5][5]) {
    int temp[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            matriz[i][j] = temp[i][j];
}


void matriz_cruz(int matriz[5][5]) {
    int temp[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            matriz[i][j] = temp[i][j];
}


void matriz_octaedro(int matriz[5][5]) {
    int temp[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            matriz[i][j] = temp[i][j];
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    int matriz_c[5][5], matriz_cr[5][5], matriz_o[5][5];

    inicializar_tabuleiro(tabuleiro);

   
    posicionar_navio(tabuleiro, 1, 1, 0, 0); 
    posicionar_navio(tabuleiro, 4, 6, 1, 0); 
    posicionar_navio(tabuleiro, 2, 2, 0, 1); 
    posicionar_navio(tabuleiro, 6, 8, 0, 2); 

    matriz_cone(matriz_c);
    matriz_cruz(matriz_cr);
    matriz_octaedro(matriz_o);

    aplicar_habilidade(tabuleiro, matriz_c, 0, 3);
    aplicar_habilidade(tabuleiro, matriz_cr, 5, 5);
    aplicar_habilidade(tabuleiro, matriz_o, 7, 3);

    exibir_tabuleiro(tabuleiro);

    return 0;
}
