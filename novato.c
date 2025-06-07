#include <stdio.h>

int main() {
    // Definindo tamanho do tabuleiro e dos navios
    int tabuleiro[10][10];      // Matriz 10x10 do tabuleiro
    int navio1[3] = {3, 3, 3};  // Navio horizontal (tamanho 3)
    int navio2[3] = {3, 3, 3};  // Navio vertical (tamanho 3)
    int i, j;

    // Inicializa o tabuleiro com água (0)
    for(i = 0; i < 10; i++) {
        for(j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Posiciona o navio1 horizontalmente a partir da linha 2, coluna 3
    int linha_navio1 = 2;
    int coluna_navio1 = 3;
    for(j = 0; j < 3; j++) {
        tabuleiro[linha_navio1][coluna_navio1 + j] = navio1[j];
    }

    // Posiciona o navio2 verticalmente a partir da linha 5, coluna 7
    int linha_navio2 = 5;
    int coluna_navio2 = 7;
    for(i = 0; i < 3; i++) {
        tabuleiro[linha_navio2 + i][coluna_navio2] = navio2[i];
    }

    // Exibe o tabuleiro
    printf("Tabuleiro de Batalha Naval:\n");
    for(i = 0; i < 10; i++) {
        for(j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
