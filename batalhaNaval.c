#include <stdio.h>

int main() {
    int tabuleiro[10][10];

    // Inicialização do tabuleiro com 0
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    //posição dos navios
    tabuleiro[0][4] = 3;
    tabuleiro[0][5] = 3;
    tabuleiro[0][6] = 3;
    tabuleiro[1][9] = 3;
    tabuleiro[2][9] = 3;
    tabuleiro[3][9] = 3;


    // Impressão das letras do topo
    printf("    "); // Espaço para alinhar com a coluna de números
    for (char letra = 'A'; letra <= 'J'; letra++) {
        printf("%c   ", letra);
    }
    printf("\n");

    // Impressão do tabuleiro com os números da lateral
    for (int i = 0; i < 10; i++) {
        printf("%2d  ", i + 1); // Números da lateral esquerda
        for (int j = 0; j < 10; j++) {
            printf("%d   ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
