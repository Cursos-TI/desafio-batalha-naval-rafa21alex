#include <stdio.h>

#define TAM 10
#define TAM_HAB 5

void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = 0;
}

void posicionarNavios(int tabuleiro[TAM][TAM]) {
    // Navios fixos
    tabuleiro[0][4] = 3; // 1E
    tabuleiro[1][5] = 3; // 2F
    tabuleiro[1][6] = 3; // 2G
    tabuleiro[1][9] = 3; // 2J
    tabuleiro[2][9] = 3; // 3J
    tabuleiro[3][9] = 3; // 4J

    tabuleiro[4][0] = 3; // 5A
    tabuleiro[5][1] = 3; // 6B
    tabuleiro[6][2] = 3; // 7C

    tabuleiro[7][7] = 3; // 8H
    tabuleiro[8][8] = 3; // 9I
    tabuleiro[9][9] = 3; // 10J
}

void construirCone(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (j >= TAM_HAB / 2 - i && j <= TAM_HAB / 2 + i)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

void construirCruz(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB / 2 || j == TAM_HAB / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

void construirOctaedro(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - TAM_HAB / 2) + abs(j - TAM_HAB / 2) <= TAM_HAB / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

void aplicarHabilidade(int tabuleiro[TAM][TAM], int hab[TAM_HAB][TAM_HAB], int origem_linha, int origem_coluna) {
    int offset = TAM_HAB / 2;

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int linha = origem_linha - offset + i;
            int coluna = origem_coluna - offset + j;

            if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM) {
                if (hab[i][j] == 1 && tabuleiro[linha][coluna] == 0)
                    tabuleiro[linha][coluna] = 5;
            }
        }
    }
}

void imprimirTabuleiro(int tabuleiro[TAM][TAM]) {
    // Cabeçalho
    printf("    ");
    for (char letra = 'A'; letra <= 'J'; letra++) {
        printf("%c   ", letra);
    }
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d  ", i + 1);
        for (int j = 0; j < TAM; j++) {
            printf("%d   ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);

    construirCone(cone);
    construirCruz(cruz);
    construirOctaedro(octaedro);

    // Aplicar habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, 1, 4);      // Cone centrado em 2E
    aplicarHabilidade(tabuleiro, cruz, 5, 5);      // Cruz centrada em 6F
    aplicarHabilidade(tabuleiro, octaedro, 8, 2);  // Octaedro centrado em 9C

    imprimirTabuleiro(tabuleiro);

    return 0;
}