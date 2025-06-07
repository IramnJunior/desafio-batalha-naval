#include <stdio.h>
#include <stdlib.h>


// Função para exibir o tabuleiro
void exibirTabuleiro(int tab[10][10]) {
    int i, j;
    for(i = 0; i < 10; i++) {
        for(j = 0; j < 10; j++) {
            // Exibe diferentes caracteres para cada tipo
            if(tab[i][j] == 0)
                printf("~ "); // água
            else if(tab[i][j] == 3)
                printf("N "); // navio
            else if(tab[i][j] == 5)
                printf("* "); // área de efeito
            else
                printf("? "); // caso haja outro valor
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int i, j;
    int tabuleiro[10][10];

    // Inicializa o tabuleiro com água (0)
    for(i = 0; i < 10; i++) {
        for(j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Navio horizontal
    for(j = 2; j < 5; j++) {
        tabuleiro[1][j] = 3;
    }
    // Navio vertical
    for(i = 5; i < 8; i++) {
        tabuleiro[i][7] = 3;
    }

    // Navio diagonal principal
    for(i = 0; i < 3; i++) {
        tabuleiro[i][i] = 3;
    }
    // Navio diagonal secundária
    for(i = 0; i < 3; i++) {
        tabuleiro[i][9 - i] = 3;
    }

    printf("Tabuleiro original:\n");
    exibirTabuleiro(tabuleiro);

    // ----- Habilidade Cone -----
    int cone[5][5];
    // Cria a matriz cone (1 no topo, expande para baixo)
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            // Área do cone: centro em cima, aumenta para baixo
            if(j >= 2 - i && j <= 2 + i)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }
    // Posição do topo do cone no tabuleiro (linha, coluna)
    int origem_cone_l = 3;
    int origem_cone_c = 3;

    // Sobrepõe o cone no tabuleiro, usando 5 como área de efeito
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            int linha = origem_cone_l + i;
            int coluna = origem_cone_c + j;
            // Só coloca se estiver dentro do tabuleiro e não for navio
            if(linha < 10 && coluna < 10 && cone[i][j] == 1 && tabuleiro[linha][coluna] != 3)
                tabuleiro[linha][coluna] = 5;
        }
    }

    printf("Tabuleiro com habilidade CONE:\n");
    exibirTabuleiro(tabuleiro);

    // ----- Habilidade Cruz -----
    // Volta o tabuleiro ao original (sem áreas de efeito)
    for(i = 0; i < 10; i++)
        for(j = 0; j < 10; j++)
            if(tabuleiro[i][j] == 5) tabuleiro[i][j] = 0;

    int cruz[5][5];
    // Centro da cruz é (2,2)
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            if(i == 2 || j == 2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }
    int origem_cruz_l = 5;
    int origem_cruz_c = 5;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            int linha = origem_cruz_l + i - 2;
            int coluna = origem_cruz_c + j - 2;
            if(linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10 && cruz[i][j] == 1 && tabuleiro[linha][coluna] != 3)
                tabuleiro[linha][coluna] = 5;
        }
    }
    printf("Tabuleiro com habilidade CRUZ:\n");
    exibirTabuleiro(tabuleiro);

    // ----- Habilidade Octaedro (losango) -----
    // Volta o tabuleiro ao original (sem áreas de efeito)
    for(i = 0; i < 10; i++)
        for(j = 0; j < 10; j++)
            if(tabuleiro[i][j] == 5) tabuleiro[i][j] = 0;

    int octaedro[5][5];
    // Centro é (2,2), formato de losango
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            if(abs(i - 2) + abs(j - 2) <= 2)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }
    int origem_octa_l = 6;
    int origem_octa_c = 2;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            int linha = origem_octa_l + i - 2;
            int coluna = origem_octa_c + j - 2;
            if(linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10 && octaedro[i][j] == 1 && tabuleiro[linha][coluna] != 3)
                tabuleiro[linha][coluna] = 5;
        }
    }
    printf("Tabuleiro com habilidade OCTAEDRO:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
