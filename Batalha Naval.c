#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10
#define TAM 5   // tamanho das matrizes de habilidade (5x5)

int main() {

    int i, j, x, y;

    // ================= TABULEIRO =================

    int tabuleiro[LINHAS][COLUNAS] = {0};

    // Navio horizontal
    tabuleiro[2][1] = 3;
    tabuleiro[2][2] = 3;
    tabuleiro[2][3] = 3;

    // Navio vertical
    tabuleiro[5][7] = 3;
    tabuleiro[6][7] = 3;
    tabuleiro[7][7] = 3;

    // Navio diagonal
    tabuleiro[9][6] = 3;
    tabuleiro[8][5] = 3;
    tabuleiro[7][4] = 3;

    tabuleiro[4][4] = 3;
    tabuleiro[3][5] = 3;
    tabuleiro[2][6] = 3;

    // ================= MATRIZES DE HABILIDADE =================

    int cone[TAM][TAM] = {0};
    int cruz[TAM][TAM] = {0};
    int octaedro[TAM][TAM] = {0};

    int centro = TAM / 2;

    // --------- Construção do CONE ---------
    for(i = 0; i < TAM; i++) {
        for(j = 0; j < TAM; j++) {
            if(j >= centro - i && j <= centro + i) {
                cone[i][j] = 1;
            }
        }
    }

    // --------- Construção da CRUZ ---------
    for(i = 0; i < TAM; i++) {
        for(j = 0; j < TAM; j++) {
            if(i == centro || j == centro) {
                cruz[i][j] = 1;
            }
        }
    }

    // --------- Construção do OCTAEDRO ---------
    for(i = 0; i < TAM; i++) {
        for(j = 0; j < TAM; j++) {
            if((i - centro) + (j - centro) <= centro) {
                octaedro[i][j] = 1;
            }
        }
    }

    // ================= POSIÇÃO DAS HABILIDADES =================

    int origemConeLinha = 1, origemConeColuna = 2;
    int origemCruzLinha = 5, origemCruzColuna = 5;
    int origemOctLinha = 7, origemOctColuna = 2;

    // ================= SOBREPOSIÇÃO DAS HABILIDADES =================

    // Cone
    for(i = 0; i < TAM; i++) {
        for(j = 0; j < TAM; j++) {

            if(cone[i][j] == 1) {
                x = origemConeLinha + i;
                y = origemConeColuna + j - centro;

                if(x >= 0 && x < LINHAS && y >= 0 && y < COLUNAS && tabuleiro[x][y] == 0) {
                    tabuleiro[x][y] = 5;
                }
            }
        }
    }

    // Cruz
    for(i = 0; i < TAM; i++) {
        for(j = 0; j < TAM; j++) {

            if(cruz[i][j] == 1) {
                x = origemCruzLinha + i - centro;
                y = origemCruzColuna + j - centro;

                if(x >= 0 && x < LINHAS && y >= 0 && y < COLUNAS && tabuleiro[x][y] == 0) {
                    tabuleiro[x][y] = 5;
                }
            }
        }
    }

    // Octaedro
    for(i = 0; i < TAM; i++) {
        for(j = 0; j < TAM; j++) {

            if(octaedro[i][j] == 1) {
                x = origemOctLinha + i - centro;
                y = origemOctColuna + j - centro;

                if(x >= 0 && x < LINHAS && y >= 0 && y < COLUNAS && tabuleiro[x][y] == 0) {
                    tabuleiro[x][y] = 5;
                }
            }
        }
    }

    // ================= EXIBIÇÃO FINAL =================

    printf("\nTABULEIRO FINAL:\n\n");

    for(i = 0; i < LINHAS; i++) {
        for(j = 0; j < COLUNAS; j++) {

            if(tabuleiro[i][j] == 0) printf(". ");
            else if(tabuleiro[i][j] == 3) printf("N ");
            else if(tabuleiro[i][j] == 5) printf("* ");
        }
        printf("\n");
    }

    return 0;
}

