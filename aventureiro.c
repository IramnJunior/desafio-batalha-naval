#include <stdio.h>

int main() {
    int tabuleiro[10][10];
    int i, j;

    // Inicializa o tabuleiro com água (0)
    for(i = 0; i < 10; i++) {
        for(j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Posiciona navio 1 (horizontal) a partir da linha 1, coluna 1
    int lin1 = 1, col1 = 1;
    for(j = 0; j < 3; j++) {
        tabuleiro[lin1][col1 + j] = 3;
    }

    // Posiciona navio 2 (vertical) a partir da linha 6, coluna 5
    int lin2 = 6, col2 = 5;
    for(i = 0; i < 3; i++) {
        tabuleiro[lin2 + i][col2] = 3;
    }

    // Posiciona navio 3 (diagonal principal) a partir de (0,0)
    int inicio_diag1 = 0;
    for(i = 0; i < 3; i++) {
        tabuleiro[inicio_diag1 + i][inicio_diag1 + i] = 3;
    }

    // Posiciona navio 4 (diagonal secundária) a partir de (0,9)
    int lin_diag2 = 0, col_diag2 = 9;
    for(i = 0; i < 3; i++) {
        tabuleiro[lin_diag2 + i][col_diag2 - i] = 3;
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
