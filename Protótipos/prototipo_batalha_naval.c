#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#define LINHAS 17
#define COLUNAS 17
#define NUM_COURACADOS 2
#define NUM_TORPEDEIROS 3
#define NUM_HIDROAVIOES 4
#define STRINGS 289
#define NUM_CHAR 7

// STRUCT
typedef struct {
    int linha;
    int coluna;
} jogada;
// FIM STRUCT

// PROTÓTIPOS
void posicionar_armada (int** tabuleiro_baixo1, int** tabuleiro_baixo2);
void portaavioes (int** tabuleiro_baixo);
void couracados (int** tabuleiro_baixo);
void torpedeiros (int** tabuleiro_baixo);
void hidroavioes (int** tabuleiro_baixo);
char** design_tabuleiro_alto ();
jogada pow ();
void printar_tabuleiro (char **tabuleiro_alto);
void jogo (int** tabuleiro_baixo1, int** tabuleiro_baixo2, char **tabuleiro_alto1, char **tabuleiro_alto2);
// FIM DOS PROTÓTIPOS

// MAIN FUNCTION
int main (){
    int **tabuleiro_baixo1 = (int **) calloc (LINHAS, sizeof(int *));
    int **tabuleiro_baixo2 = (int **) calloc (LINHAS, sizeof(int *));
    for (int i = 0; i < LINHAS; i++){
        tabuleiro_baixo1[i] = (int *) calloc (COLUNAS, sizeof (int));
        tabuleiro_baixo2[i] = (int *) calloc (COLUNAS, sizeof (int));
    }
    posicionar_armada(tabuleiro_baixo1, tabuleiro_baixo2);
    char **tabuleiro_alto1 = design_tabuleiro_alto();
    char **tabuleiro_alto2 = design_tabuleiro_alto();

    jogo(tabuleiro_baixo1, tabuleiro_baixo2, tabuleiro_alto1, tabuleiro_alto2);

    for (int i = 0; i < LINHAS; i++){
        free (tabuleiro_baixo1[i]);
        free (tabuleiro_baixo2[i]);
    }
    free (tabuleiro_baixo1);
    free (tabuleiro_baixo2);

    for (int i = 0; i < STRINGS; i++){
        free (tabuleiro_alto1[i]);
        free (tabuleiro_alto2[i]);
    }
    free (tabuleiro_alto1);
    free (tabuleiro_alto2);

    return 0;
}
// END MAIN

// AUX FUNCTIONS
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

void portaavioes (int** tabuleiro_baixo){
    int linhaP, colunaP;
    srand(time(NULL));
    linhaP = 2 + (rand() % 12);
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

void torpedeiros (int** tabuleiro_baixo){
    int linha, coluna;
    do{
        srand(time(NULL));
        linha = 2 + (rand() % 13);
        coluna = 2 + (rand() % 13);
    }while(tabuleiro_baixo[linha][coluna] != 0 || tabuleiro_baixo[linha][coluna - 1] != 0 || tabuleiro_baixo[linha][coluna + 1] != 0 || tabuleiro_baixo[linha - 1][coluna] != 0 || tabuleiro_baixo[linha - 1][coluna + 1] != 0 || tabuleiro_baixo[linha + 1][coluna - 1] != 0 || tabuleiro_baixo[linha + 1][coluna] != 0);
    for (int j = coluna; j <= (coluna + 1); j++) tabuleiro_baixo[linha - 1][j] = 4;
    for (int j = (coluna - 1); j <= (coluna + 1); j++) tabuleiro_baixo[linha][j] = 4;
    for (int j = (coluna - 1); j <= coluna; j++) tabuleiro_baixo[linha + 1][j] = 4;
}

void hidroavioes (int** tabuleiro_baixo){
    int linha, coluna;
    do{
        srand(time(NULL));
        linha = 1 + (rand() % 14);
        coluna = 5 + (rand() % 8);
    }while(tabuleiro_baixo[linha][coluna - 4] != 0 || tabuleiro_baixo[linha][coluna - 2] != 0 || tabuleiro_baixo[linha][coluna] != 0 || tabuleiro_baixo[linha][coluna + 2] != 0 || tabuleiro_baixo[linha + 1][coluna - 3] != 0 || tabuleiro_baixo[linha + 1][coluna - 1] != 0 || tabuleiro_baixo[linha + 1][coluna + 1] != 0 || tabuleiro_baixo[linha + 1][coluna + 3] != 0);
    for (int j = (coluna - 4); j <= (coluna + 2); j = (j + 2)) tabuleiro_baixo[linha][j] = 5;
    for (int j = (coluna - 3); j <= (coluna + 3); j = (j + 2)) tabuleiro_baixo[linha + 1][j] = 5;
}

char** design_tabuleiro_alto (){
    int c = 17;

    char **tabuleiro_alto = (char **) malloc (STRINGS * sizeof(char *));
    for(int i = 0; i < STRINGS; i++){
        tabuleiro_alto[i] = (char *) malloc (NUM_CHAR * sizeof(char));
    }

    tabuleiro_alto[0] = "|    |";
    tabuleiro_alto[1] = " A |";
    tabuleiro_alto[2] = " B |";
    tabuleiro_alto[3] = " C |";
    tabuleiro_alto[4] = " D |";
    tabuleiro_alto[5] = " E |";
    tabuleiro_alto[6] = " F |";
    tabuleiro_alto[7] = " G |";
    tabuleiro_alto[8] = " H |";
    tabuleiro_alto[9] = " I |";
    tabuleiro_alto[10] = " J |";
    tabuleiro_alto[11] = " K |";
    tabuleiro_alto[12] = " L |";
    tabuleiro_alto[13] = " M |";
    tabuleiro_alto[14] = " N |";
    tabuleiro_alto[15] = " O |";
    tabuleiro_alto[16] = " P |"; 
    tabuleiro_alto[17] = "| 1  |";
    tabuleiro_alto[34] = "| 2  |";
    tabuleiro_alto[51] = "| 3  |";
    tabuleiro_alto[68] = "| 4  |";
    tabuleiro_alto[85] = "| 5  |";
    tabuleiro_alto[102] = "| 6  |";
    tabuleiro_alto[119] = "| 7  |";
    tabuleiro_alto[136] = "| 8  |";        
    tabuleiro_alto[153] = "| 9  |";
    tabuleiro_alto[170] = "| 10 |";
    tabuleiro_alto[187] = "| 11 |";
    tabuleiro_alto[204] = "| 12 |";
    tabuleiro_alto[221] = "| 13 |";
    tabuleiro_alto[238] = "| 14 |";
    tabuleiro_alto[255] = "| 15 |";
    tabuleiro_alto[272] = "| 16 |";
    for (int i = 17; i < STRINGS; i++){
        if (c == 17) c = 0;
        else {
            tabuleiro_alto[i] = "   |";
        }
        c++;
    }

    return (tabuleiro_alto);
}

jogada pow (){
    char comando[8];
    jogada coordenadas;
    printf("\nOnde vai atacar? ");
    scanf("%s", comando);                                                                                                             
    for (int i = 0; i <= strlen(comando); i++) comando[i] = toupper(comando[i]);  
    if (comando[0] == 'P' && comando[1] == 'O' && comando[2] == 'W'){
        char coordenadas_ins[4], letra;
        scanf("%s", coordenadas_ins);
        coordenadas.linha = atoi(coordenadas_ins);
        if (coordenadas.linha <= 0 || coordenadas.linha > 16){
            printf("ERRO! Posicao Invalida!");
            pow();
        }
        else{
            letra = coordenadas_ins [strlen(coordenadas_ins) - 1]; 
            switch (letra) {
                case 'A':
                    coordenadas.coluna = 1;
                    break;
                case 'B':
                    coordenadas.coluna = 2;
                    break;
                case 'C':
                    coordenadas.coluna = 3;
                    break;
                case 'D':
                    coordenadas.coluna = 4;
                    break;
                case 'E':
                    coordenadas.coluna = 5;
                    break;
                case 'F':
                    coordenadas.coluna = 6;
                    break;
                case 'G':
                    coordenadas.coluna = 7;
                    break;
                case 'H':
                    coordenadas.coluna = 8;
                    break;
                case 'I':
                    coordenadas.coluna = 9;
                    break;
                case 'J':
                    coordenadas.coluna = 10;
                    break;
                case 'K':
                    coordenadas.coluna = 11;
                    break;
                case 'L':
                    coordenadas.coluna = 12;
                    break;
                case 'M':
                    coordenadas.coluna = 13;
                    break;
                case 'N':
                    coordenadas.coluna = 14;
                    break;
                case 'O':
                    coordenadas.coluna = 15;
                    break;
                case 'P':
                    coordenadas.coluna = 16;
                    break;
                default:
                    printf("ERRO! Essa posicao nao existe!");
                    pow();
                    break;
            }
            return (coordenadas);
        }
    }
    else {
        printf("ERRO! Comando invalido.");
        pow ();
    }
}

void printar_tabuleiro (char **tabuleiro_alto){
    int c = 0;
    for(int i = 0; i < STRINGS; i++){
        c++;
        if (c == 17){
            c = 0;
            printf("%s\n", tabuleiro_alto[i]);
        }
        else {
            printf("%s", tabuleiro_alto[i]);
        }
    }
}

void jogo (int** tabuleiro_baixo1, int** tabuleiro_baixo2, char **tabuleiro_alto1, char **tabuleiro_alto2){
    while (1){
        jogada jogador1, jogador2;
        // Jogador 1
        printf("------------------------------ JOGADOR 1 -----------------------------\n\n");
        printar_tabuleiro(tabuleiro_alto2);
        jogador1 = pow();                       // Essa função retorna uma struct com jogador1.linha e jogador1.coluna
        int posicao_array = (jogador1.linha * 17) + jogador1.coluna;
        switch (tabuleiro_baixo2[jogador1.linha][jogador1.coluna]){
            case 0:
                tabuleiro_alto2 [posicao_array] = " * |";
                break;
            case 2:
                tabuleiro_alto2 [posicao_array] = "P2 |";
                break;
            case 3:
                tabuleiro_alto2 [posicao_array] = "C2 |";
                break;
            case 4:
                tabuleiro_alto2 [posicao_array] = "T2 |";
                break;
            case 5:
                tabuleiro_alto2 [posicao_array] = "H2 |";
                break;
        }
        printar_tabuleiro(tabuleiro_alto2);
        printf("----------------------------------------------------------------------\n\n");
        Sleep(2000);
        // Jogador 2
        printf("------------------------------ JOGADOR 2 -----------------------------\n\n");
        printar_tabuleiro(tabuleiro_alto1);
        jogador2 = pow();                       // Essa função retorna uma struct com jogador2.linha e jogador2.coluna
        posicao_array = (jogador2.linha * 17) + jogador2.coluna;
        switch (tabuleiro_baixo1[jogador2.linha][jogador2.coluna]){
            case 0:
                tabuleiro_alto1 [posicao_array] = " * |";
                break;
            case 2:
                tabuleiro_alto1 [posicao_array] = "P2 |";
                break;
            case 3:
                tabuleiro_alto1 [posicao_array] = "C2 |";
                break;
            case 4:
                tabuleiro_alto1 [posicao_array] = "T2 |";
                break;
            case 5:
                tabuleiro_alto1 [posicao_array] = "H2 |";
                break;
        }
        printar_tabuleiro(tabuleiro_alto1);
        printf("----------------------------------------------------------------------\n\n");
    }
}

// END AUX

/*
|    | A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P |
| 1  |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 2  |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 3  |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 4  |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 5  |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 6  |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 7  |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 8  |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 9  |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 10 |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 11 |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 12 |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 13 |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 14 |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 15 |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 16 |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
*/