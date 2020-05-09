#include "lib_naval.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_COURACADOS 2
#define NUM_TORPEDEIROS 3
#define NUM_HIDROAVIOES 4

void portaavioes (int** tabuleiro_baixo){
    srand(time(NULL)*time(NULL));
    int linhaP = 2 + (rand() % 12);
    srand(time(NULL));
    int colunaP = 3 + (rand() % 11);
    for (int i = (colunaP - 2); i <= (colunaP + 2); i++) tabuleiro_baixo[linhaP][i] = 2;
    for (int j = (linhaP - 1); j <= (linhaP + 2); j++) {
        tabuleiro_baixo[j][colunaP - 1] = 2;
        tabuleiro_baixo[j][colunaP + 1] = 2;
    }
}

void couracados (int** tabuleiro_baixo){
    int linhaC, colunaC;
    do{
        srand(time(NULL)*time(NULL));
        linhaC = 3 + (rand() % 10);
        srand(time(NULL));
        colunaC = 3 + (rand() % 11);
    } while (tabuleiro_baixo[linhaC][colunaC - 2] != 0 || tabuleiro_baixo[linhaC][colunaC - 1] != 0 || tabuleiro_baixo[linhaC][colunaC] != 0 || tabuleiro_baixo[linhaC][colunaC + 1] != 0 || tabuleiro_baixo[linhaC][colunaC + 2] != 0 || tabuleiro_baixo[linhaC - 2][colunaC + 1] != 0 || tabuleiro_baixo[linhaC - 1][colunaC + 1] != 0 || tabuleiro_baixo[linhaC + 1][colunaC - 1] != 0 || tabuleiro_baixo[linhaC + 2][colunaC - 1] != 0 || tabuleiro_baixo[linhaC + 3][colunaC - 1] != 0);   
    for (int i = (colunaC - 2); i <= (colunaC + 2); i++) tabuleiro_baixo[linhaC][i] = 3;
    for (int j = (linhaC - 2); j < linhaC; j++) tabuleiro_baixo[j][colunaC + 1] = 3;
    for (int j = (linhaC + 1); j <= (linhaC + 3); j++) tabuleiro_baixo[j][colunaC - 1] = 3;
}

void torpedeiros (int** tabuleiro_baixo){
    int linha, coluna;
    do{
        srand(time(NULL)*time(NULL));
        linha = 2 + (rand() % 13);
        srand(time(NULL));
        coluna = 2 + (rand() % 13);
    }while(tabuleiro_baixo[linha][coluna] != 0 || tabuleiro_baixo[linha][coluna - 1] != 0 || tabuleiro_baixo[linha][coluna + 1] != 0 || tabuleiro_baixo[linha - 1][coluna] != 0 || tabuleiro_baixo[linha - 1][coluna + 1] != 0 || tabuleiro_baixo[linha + 1][coluna - 1] != 0 || tabuleiro_baixo[linha + 1][coluna] != 0);
    for (int j = coluna; j <= (coluna + 1); j++) tabuleiro_baixo[linha - 1][j] = 4;
    for (int j = (coluna - 1); j <= (coluna + 1); j++) tabuleiro_baixo[linha][j] = 4;
    for (int j = (coluna - 1); j <= coluna; j++) tabuleiro_baixo[linha + 1][j] = 4;
}

void hidroavioes (int** tabuleiro_baixo){
    int linha, coluna;
    do{
        srand(time(NULL)*time(NULL));
        linha = 1 + (rand() % 14);
        srand(time(NULL));
        coluna = 5 + (rand() % 8);
    }while(tabuleiro_baixo[linha][coluna - 4] != 0 || tabuleiro_baixo[linha][coluna - 2] != 0 || tabuleiro_baixo[linha][coluna] != 0 || tabuleiro_baixo[linha][coluna + 2] != 0 || tabuleiro_baixo[linha + 1][coluna - 3] != 0 || tabuleiro_baixo[linha + 1][coluna - 1] != 0 || tabuleiro_baixo[linha + 1][coluna + 1] != 0 || tabuleiro_baixo[linha + 1][coluna + 3] != 0);
    for (int j = (coluna - 4); j <= (coluna + 2); j = (j + 2)) tabuleiro_baixo[linha][j] = 5;
    for (int j = (coluna - 3); j <= (coluna + 3); j = (j + 2)) tabuleiro_baixo[linha + 1][j] = 5;
}

void posicionar_armada (int** tabuleiro_baixo1, int** tabuleiro_baixo2){
    //Posicionamento dos porta-aviões(P) no tabuleiro do jogador 1 e 2
    portaavioes (tabuleiro_baixo1);
    portaavioes (tabuleiro_baixo2);
    //Posicionamento dos couraçados (C) no tabuleiro do jogador 1 e 2
    for (int i = 1; i <= NUM_COURACADOS; i++){
        couracados(tabuleiro_baixo1);
        couracados(tabuleiro_baixo2);
    }
    //Posicionamento dos torpedeiros (T) no tabuleiro do jogador 1 e 2
    for (int i = 1; i <= NUM_TORPEDEIROS; i++){
        torpedeiros(tabuleiro_baixo1);
        torpedeiros(tabuleiro_baixo2);
    }
    //Posicionamento dos hidroaviões (H) no tabuleiro do jogador 1 e 2
    for (int i = 1; i <= NUM_HIDROAVIOES; i++){
        hidroavioes(tabuleiro_baixo1);
        hidroavioes(tabuleiro_baixo2);
    }
}