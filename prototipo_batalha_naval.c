#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINHAS 17
#define COLUNAS 17

// PROTÓTIPOS
void posicionar_armada (int** tabuleiro_baixo1, int** tabuleiro_baixo2);
void portaavioes (int** tabuleiro_baixo);
void couracados (int** tabuleiro_baixo);
// FIM DOS PROTÓTIPOS

// MAIN FUNCTION
int main (){
    int **tabuleiro_baixo1 = malloc (LINHAS * sizeof(*tabuleiro_baixo1));
    int **tabuleiro_baixo2 = malloc (LINHAS * sizeof(*tabuleiro_baixo2));
    for (int i = 0; i < LINHAS; i++){
        tabuleiro_baixo1[i] = malloc (COLUNAS * sizeof (*tabuleiro_baixo1[i]));
        tabuleiro_baixo2[i] = malloc (COLUNAS * sizeof (*tabuleiro_baixo2[i]));
    }
    posicionar_armada(tabuleiro_baixo1, tabuleiro_baixo2);
    for(int i = 0; i < LINHAS; i++){
        for (int j = 0; j < COLUNAS; j++){
            if (j == (COLUNAS - 1)) printf("%d\n", tabuleiro_baixo1[i][j]);
            else printf("%d ", tabuleiro_baixo1[i][j]);
        }
    }
    free (tabuleiro_baixo1);
    free (tabuleiro_baixo2);
    return 0;
}
// FIM MAIN

// AUX FUNCTIONS
void posicionar_armada (int** tabuleiro_baixo1, int** tabuleiro_baixo2){
    for (int i = 0; i < LINHAS; i++){
        for (int j = 0; j < COLUNAS; j++){
            tabuleiro_baixo1[i][j] = 0;
            tabuleiro_baixo2[i][j] = 0;
        }
    }
    //Posicionamento dos porta-aviões(P) no tabuleiro do jogador 1 e 2
    portaavioes (tabuleiro_baixo1);
    portaavioes (tabuleiro_baixo2);
    //Posicionamento do couraçado 1 (C) no tabuleiro do jogador 1 e 2
    couracados(tabuleiro_baixo1);
    couracados(tabuleiro_baixo2);
    //Posicionamento do couraçado 1 (C) no tabuleiro do jogador 1 e 2
    couracados(tabuleiro_baixo1);
    couracados(tabuleiro_baixo2);
}

void portaavioes (int** tabuleiro_baixo){
    int linhaP, colunaP;
    srand(time(NULL));
    linhaP = 2 + (rand() % 11);
    colunaP = 3 + (rand() % 11);
    for (int i = (colunaP - 2); i <= (colunaP + 2); i++) tabuleiro_baixo[linhaP][i] = 2;
    for (int j = (linhaP - 1); j <= (linhaP + 2); j++) {
        tabuleiro_baixo[j][colunaP - 1] = 2;
        tabuleiro_baixo[j][colunaP + 1] = 2;
    }
}

void couracados (int** tabuleiro_baixo){
    int linhaC, colunaC;
    do{
        srand(time(NULL));
        linhaC = 3 + (rand() % 10);
        colunaC = 3 + (rand() % 11);
    } while (tabuleiro_baixo[linhaC][colunaC - 2] != 0 || tabuleiro_baixo[linhaC][colunaC - 1] != 0 || tabuleiro_baixo[linhaC][colunaC] != 0 || tabuleiro_baixo[linhaC][colunaC + 1] != 0 || tabuleiro_baixo[linhaC][colunaC + 2] != 0 || tabuleiro_baixo[linhaC - 2][colunaC + 1] != 0 || tabuleiro_baixo[linhaC - 1][colunaC + 1] != 0 || tabuleiro_baixo[linhaC + 1][colunaC - 1] != 0 || tabuleiro_baixo[linhaC + 2][colunaC - 1] != 0 || tabuleiro_baixo[linhaC + 3][colunaC - 1] != 0);   
    for (int i = (colunaC - 2); i <= (colunaC + 2); i++) tabuleiro_baixo[linhaC][i] = 3;
    for (int j = (linhaC - 2); j < linhaC; j++) tabuleiro_baixo[j][colunaC + 1] = 3;
    for (int j = (linhaC + 1); j <= (linhaC + 3); j++) tabuleiro_baixo[j][colunaC - 1] = 3;
}
// FIM AUX