#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>
#include "lib_naval.h"

#define LINHAS 17
#define COLUNAS 17
#define STRINGS 289
#define NUM_CHAR 7

// STRUCT
typedef struct {
    int linha;
    int coluna;
} jogada;

typedef struct {
    unsigned long int segundos;
    unsigned long int minutos;
    unsigned long int horas;
} struct_relogio;

// FIM STRUCT

// PROTÓTIPOS
char** design_tabuleiro_alto ();
jogada pow ();
void printar_tabuleiro (char **tabuleiro_alto);
struct_relogio relogio (clock_t clock_inicial);
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
            switch (toupper(letra)) {
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

struct_relogio relogio (clock_t clock_inicial){
    struct_relogio relogio;
    
    relogio.minutos = 0;
    relogio.horas = 0;

    relogio.segundos = (clock() - clock_inicial)/CLOCKS_PER_SEC;

    while (relogio.segundos > 60){
        relogio.minutos++;
        relogio.segundos = relogio.segundos - 60;
    }
    while (relogio.minutos > 60){
        relogio.horas++;
        relogio.minutos = relogio.minutos - 60;
    }
    return relogio;
}

void jogo (int** tabuleiro_baixo1, int** tabuleiro_baixo2, char **tabuleiro_alto1, char **tabuleiro_alto2){
    clock_t clock_inicial = clock();
    int j1 = 0;
    int j2 = 0;
    while (1){
        jogada jogador1, jogador2;

        struct_relogio tempo_jogo = relogio(clock_inicial);

        // Jogador 1
        RETURN_JOGADOR_1:
            printf("------------------------------ JOGADOR 1 -----------------------------\n\n");
            printf("%02lu: %02lu: %02lu\n", tempo_jogo.horas, tempo_jogo.minutos, tempo_jogo.segundos);
            printar_tabuleiro(tabuleiro_alto2);
            jogador1 = pow();                       // Essa função retorna uma struct com jogador1.linha e jogador1.coluna
            int posicao_array = (jogador1.linha * 17) + jogador1.coluna;
            switch (tabuleiro_baixo2[jogador1.linha][jogador1.coluna]){
                case 0:
                    tabuleiro_alto2 [posicao_array] = " * |";
                    break;
                case 2:
                    tabuleiro_alto2 [posicao_array] = "P2 |";
                    tabuleiro_baixo2[jogador1.linha][jogador1.coluna] = 6;
                    j1++;
                    break;
                case 3:
                    tabuleiro_alto2 [posicao_array] = "C2 |";
                    tabuleiro_baixo2[jogador1.linha][jogador1.coluna] = 6;
                    j1++;
                    break;
                case 4:
                    tabuleiro_alto2 [posicao_array] = "T2 |";
                    tabuleiro_baixo2[jogador1.linha][jogador1.coluna] = 6;
                    j1++;
                    break;
                case 5:
                    tabuleiro_alto2 [posicao_array] = "H2 |";
                    tabuleiro_baixo2[jogador1.linha][jogador1.coluna] = 6;
                    j1++;
                    break;
                case 6:
                    printf("Voce ja atirou nesse local! Tente novamente!\n");
                    goto RETURN_JOGADOR_1;
            }
            printar_tabuleiro(tabuleiro_alto2);
            printf("----------------------------------------------------------------------\n\n");
            if (j1 == 84){
                printf("Parabens JOGADOR 1. Voce venceu!\n");
                break;
            }
            Sleep(2000);

        // Jogador 2
        tempo_jogo = relogio(clock_inicial);
        RETURN_JOGADOR_2:
            printf("------------------------------ JOGADOR 2 -----------------------------\n\n");
            printf("%02lu: %02lu: %02lu\n", tempo_jogo.horas, tempo_jogo.minutos, tempo_jogo.segundos);
            printar_tabuleiro(tabuleiro_alto1);
            jogador2 = pow();                       // Essa função retorna uma struct com jogador2.linha e jogador2.coluna
            posicao_array = (jogador2.linha * 17) + jogador2.coluna;
            switch (tabuleiro_baixo1[jogador2.linha][jogador2.coluna]){
                case 0:
                    tabuleiro_alto1 [posicao_array] = " * |";
                    break;
                case 2:
                    tabuleiro_alto1 [posicao_array] = "P1 |";
                    tabuleiro_baixo1[jogador2.linha][jogador2.coluna] = 6;
                    j2++;
                    break;
                case 3:
                    tabuleiro_alto1 [posicao_array] = "C1 |";
                    tabuleiro_baixo1[jogador2.linha][jogador2.coluna] = 6;
                    j2++;
                    break;
                case 4:
                    tabuleiro_alto1 [posicao_array] = "T1 |";
                    tabuleiro_baixo1[jogador2.linha][jogador2.coluna] = 6;
                    j2++;
                    break;
                case 5:
                    tabuleiro_alto1 [posicao_array] = "H1 |";
                    tabuleiro_baixo1[jogador2.linha][jogador2.coluna] = 6;
                    j2++;
                    break;
                case 6:
                    printf("Voce ja atirou nesse local! Tente novamente!\n");
                    goto RETURN_JOGADOR_2;
            }
            printar_tabuleiro(tabuleiro_alto1);
            printf("----------------------------------------------------------------------\n\n");
            if (j2 == 84){
                printf("Parabens JOGADOR 2. Voce venceu!\n");
                break;
            }
            Sleep(2000);
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
