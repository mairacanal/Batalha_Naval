/* BATALHA NAVAL
Desenvolvido por Maíra Canal e Caroline Grupe

Objetivo: Desenvolver um jogo multiplayer de Batalha Naval em linguagem C
USP - ICC1 - 2020
*/

// BIBLIOTECAS

#include <stdio.h>              //Biblioteca padrão
#include <ctype.h>              //Biblioteca para usar o toupper()
#include <string.h>             //Biblioteca para manipular strings
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <stdbool.h>
#include "lib_naval.h"

//FIM BIBLIOTECAS

// MACROS

#define LINHAS 17
#define COLUNAS 17
#define STRINGS 289
#define NUM_CHAR 7
#define PONTUA_P 43
#define PONTUA_C 78
#define PONTUA_T 82
#define PONTUA_H 125
#define PONTUA_ERRO -3

// FIM MACROS


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


// PRÓTOTIPOS
void regras ();
void printar_menu ();
void menu (char* opcao, char opmenu[7][10]);
int** alocar_tabuleiro_baixo ();
void free_tabuleiros (int** tabuleiro_baixo1, int** tabuleiro_baixo2, char **tabuleiro_alto1, char **tabuleiro_alto2);
char** design_tabuleiro_alto ();
jogada pow ();
struct_relogio relogio (clock_t clock_inicial);
void printar_jogador1(char** tabuleiro_alto2, int* pontuacao_j1, clock_t clock_inicial);
void printar_jogador2(char** tabuleiro_alto1, int* pontuacao_j2, clock_t clock_inicial);
void func_jogador1(int** tabuleiro_baixo2, char** tabuleiro_alto2, int* pontuacao_j1, int* j1, clock_t clock_inicial);
void func_jogador2(int** tabuleiro_baixo1, char** tabuleiro_alto1, int* pontuacao_j2, int* j2, clock_t clock_inicial);
// FIM DOS PRÓTOTIPOS


// MAIN FUNCTION

int main (){
    char opmenu [8][10] = {"RESET", "SAIR", "REGRAS", "MENU", "ACASO", "GRAVAR", "CARREGAR", "POW"};     //Declara as opções do menu
    char opcao_dig[10];                                                                           //Opção digitada pelo usuário
    long int tam;                                                                                //Tamanho da opção digitada pelo usuário
    clock_t clock_inicial;
    bool bjogador1 = false;
    bool bjogador2 = false;
    int j1, j2;
    int pontuacao_j1;
    int pontuacao_j2;

    int** tabuleiro_baixo1 = alocar_tabuleiro_baixo();
    int** tabuleiro_baixo2 = alocar_tabuleiro_baixo();
    char** tabuleiro_alto1 = design_tabuleiro_alto();
    char** tabuleiro_alto2 = design_tabuleiro_alto();

    printf("----------------------------------------------- BATALHA NAVAL -------------------------------------------------\n\n");
    printf("Bem vindos a Batalha Naval!\n\n");
    printar_menu ();                                                                          //Chama a função menu()

    while(1){
        printf("Digite seu comando: ");
        scanf("%s", opcao_dig);                                                       //Recebe a opção do jogador
        tam = strlen(opcao_dig);                                                      //Determina o tamanho da string digitada pelo usuário
        char opcao[tam + 1];                                                          //Declara uma variável que será utilizada para entrar nos laços do menu principal
        for (int i = 0; i <= tam; i++) opcao[i] = toupper(opcao_dig[i]);              
        
//Para evitar possíveis erros no programa, causados pela digitação de elementos com letras maiúsculas ou minúsculas, eleva-se todos os caracteres para letra maiuscula

//Início de um laço condicional para executar o comando digitado pelo usuário
//A função strcmp realiza uma comparação entra as strings do parâmetro, retornando o número 0 se elas forem iguais

        if (strcmp(opcao, opmenu[0]) == 0){
            bjogador1 = true;
            clock_inicial = clock();

            j1 = 0;
            pontuacao_j1 = 0;

            j2 = 0;
            pontuacao_j2 = 0;

            posicionar_armada(tabuleiro_baixo1, tabuleiro_baixo2);
        }

        else if (strcmp(opcao, opmenu[1]) == 0){
            free_tabuleiros (tabuleiro_baixo1, tabuleiro_baixo2, tabuleiro_alto1, tabuleiro_alto2);
            printf ("------------------------------------------- Ate a proxima partida! --------------------------------------------\n");
            printf ("---------------------------------------------------------------------------------------------------------------\n");
            printf ("|                                             Desenvolvedoras                                                 |\n");
            printf ("|                Maira Canal                                                        Caroline Grupe            |\n");
            printf ("|                                                                                                             |\n");
            printf ("|                              Agradecimentos especiais ao professor Jo Ueyama                                |\n");
            printf ("|                                                   2020                                                      |\n");
            printf ("---------------------------------------------------------------------------------------------------------------\n");
            return 0;
        }

        else if (strcmp(opcao, opmenu[2]) == 0) regras();                          //Exibe as regras pro usuário

        else if (strcmp(opcao, opmenu[3]) == 0) printar_menu();                    //Exibe o menu pro usuário

        else if (strcmp(opcao, opmenu[4]) == 0){
            posicionar_armada(tabuleiro_baixo1, tabuleiro_baixo2);
        }

        else if (strcmp(opcao, opmenu[5]) == 0){

        }

        else if (strcmp(opcao, opmenu[6]) == 0){

        }

        else if (strcmp(opcao, opmenu[7]) == 0){
            if (bjogador1 == true){
                func_jogador1 (tabuleiro_baixo2, tabuleiro_alto2, &pontuacao_j1, &j1, clock_inicial);
                bjogador1 = false;
                bjogador2 = true;
            }
            else if (bjogador2 == true){
                func_jogador2(tabuleiro_baixo1, tabuleiro_alto1, &pontuacao_j2, &j2, clock_inicial);
                bjogador1 = true;
                bjogador2 = false;
            }
        }

        else printf("ERRO! Opcao invalida. Tente novamente!\n");            //Caso o usuário tenha digitado qualquer palavra diferente da indicada no menu, será demonstrada essa mensagem de erro

        if (bjogador1 == true){
            printar_jogador1(tabuleiro_alto2, &pontuacao_j1, clock_inicial);
        }
        else if (bjogador2 == true){
            printar_jogador2(tabuleiro_alto1, &pontuacao_j2, clock_inicial);
        }
    }
    return 0;
}

// END MAIN


// AUX FUNCTIONS
void regras (){              //Função auxiliar para chamar as regras do jogo
    printf("-------------------------------------------------- REGRAS -----------------------------------------------------\n");
    printf("- A armada completa sera composta por um porta-avioes (P) com 11 blocos, dois couracados (C) com 10 blocos,\ntres torpedeiros (T) com 7 blocos e quadro hidroavioes (H) com 8 blocos.\n");
    printf("- A sua armada sera posicionada aleatoriamente no seu campo de batalha.\n");
    printf("- Para atirar nos blocos do tabuleiro, voce devera digitar POW e a posicao que deseja atingir. \nPor exemplo, pow 15A atingira a bloco da linha 15, coluna A.\n");
    printf("- Ao atirar um bloco, voce podera atingir a agua, representada pelo *, ou um elemento da armada do seu oponente.\n");
    printf("Se voce atingir um porta-avioes (P), voce recebera 43 pontos; um couracado (C), voce recebera 78 pontos; um\ntorpedeiro (T), voce recebera 82 pontos; um hidroaviao (H), voce recebera 125 pontos, e se voce atigir a agua,\nvoce perdera 3 pontos\n");
    printf("- Para ganhar o jogo, voce devera afundar todos os navios do seu oponente.\n");
    printf("---------------------------------------------------------------------------------------------------------------\n\n");
}                            //end regras

void printar_menu (){                //Função auxiliar para chamar o menu do jogo
    printf("--------------------------------------------------- MENU ------------------------------------------------------\n");
    printf("|Digite:                                                                                                      |\n");
    printf("|RESET - Iniciar uma nova partida.                                                                            |\n");
    printf("|SAIR - Abandonar o jogo, sem salvar.                                                                         |\n");
    printf("|REGRAS - Exibir as regras do jogo.                                                                           |\n");
    printf("|MENU - Exibir o menu do jogo.                                                                                |\n");
    printf("|ACASO - Iniciar um novo tabuleiro aleatorio, mas conserva seus pontos e o tempo no relogio.                  |\n");
    printf("|GRAVAR - Salvar o jogo em um arquivo com o nome tabuleiro-{timestamp}.txt.                                   |\n");
    printf("|CARREGAR {nome do arquivo} - Carregar o jogo que foi salvo.                                                  |\n");
    printf("|POW - Atirar em um bloco                                                                                     |\n");
    printf("---------------------------------------------------------------------------------------------------------------\n\n");
}                            //end menu

int** alocar_tabuleiro_baixo (){
    int** tabuleiro_baixo = (int **) calloc (LINHAS, sizeof(int *));
    for (int i = 0; i < LINHAS; i++){
        tabuleiro_baixo[i] = (int *) calloc (COLUNAS, sizeof (int));
    }
    return (tabuleiro_baixo);
}

void free_tabuleiros (int** tabuleiro_baixo1, int** tabuleiro_baixo2, char **tabuleiro_alto1, char **tabuleiro_alto2){
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
    jogada coordenadas;

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
            }

        return (coordenadas);
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

void printar_jogador1 (char** tabuleiro_alto2, int* pontuacao_j1, clock_t clock_inicial){
    struct_relogio tempo_jogo = relogio(clock_inicial);

    printf("------------------------------ JOGADOR 1 -----------------------------\n\n");
    printf("%02lu: %02lu: %02lu                               Pontuacao: %d\n", tempo_jogo.horas, tempo_jogo.minutos, tempo_jogo.segundos, *pontuacao_j1);
    printar_tabuleiro(tabuleiro_alto2);
}

void printar_jogador2 (char** tabuleiro_alto1, int* pontuacao_j2, clock_t clock_inicial){
    struct_relogio tempo_jogo = relogio(clock_inicial);

    printf("------------------------------ JOGADOR 2 -----------------------------\n\n");
    printf("%02lu: %02lu: %02lu                               Pontuacao: %d\n", tempo_jogo.horas, tempo_jogo.minutos, tempo_jogo.segundos, *pontuacao_j2);
    printar_tabuleiro(tabuleiro_alto1);
}

void func_jogador1(int** tabuleiro_baixo2, char** tabuleiro_alto2, int* pontuacao_j1, int* j1, clock_t clock_inicial){
    
    int posicao_array;
    jogada jogador1;

    jogador1 = pow();
    posicao_array = (jogador1.linha * 17) + jogador1.coluna;

    switch (tabuleiro_baixo2[jogador1.linha][jogador1.coluna]){
        case 0:
            tabuleiro_alto2 [posicao_array] = " * |";
            tabuleiro_baixo2[jogador1.linha][jogador1.coluna] = 6;
            *pontuacao_j1 = *pontuacao_j1 + PONTUA_ERRO;
            break;
        case 2:
            tabuleiro_alto2 [posicao_array] = "P2 |";
            tabuleiro_baixo2[jogador1.linha][jogador1.coluna] = 6;
            *pontuacao_j1 = *pontuacao_j1 + PONTUA_P;
            *j1++;
            break;
        case 3:
            tabuleiro_alto2 [posicao_array] = "C2 |";
            tabuleiro_baixo2[jogador1.linha][jogador1.coluna] = 6;
            *pontuacao_j1 = *pontuacao_j1 + PONTUA_C;
            *j1++;
            break;
        case 4:
            tabuleiro_alto2 [posicao_array] = "T2 |";
            tabuleiro_baixo2[jogador1.linha][jogador1.coluna] = 6;
            *pontuacao_j1 = *pontuacao_j1 + PONTUA_T;
            *j1++;
            break;
        case 5:
            tabuleiro_alto2 [posicao_array] = "H2 |";
            tabuleiro_baixo2[jogador1.linha][jogador1.coluna] = 6;
            *pontuacao_j1 = *pontuacao_j1 + PONTUA_H;
            *j1++;
            break;
        case 6:
            printf("Voce ja atirou nesse local! Tente novamente!\n");
            func_jogador1(tabuleiro_baixo2, tabuleiro_alto2, pontuacao_j1, j1, clock_inicial);
        }

    printar_tabuleiro(tabuleiro_alto2);
    printf("----------------------------------------------------------------------\n\n");

    if (*j1 == 84){
        printf("Parabens JOGADOR 1. Voce venceu!\n");
    }

    Sleep(2000);
}

void func_jogador2(int** tabuleiro_baixo1, char** tabuleiro_alto1, int* pontuacao_j2, int* j2, clock_t clock_inicial){
    int posicao_array;
    jogada jogador2;

    jogador2 = pow();                       // Essa função retorna uma struct com jogador2.linha e jogador2.coluna
    posicao_array = (jogador2.linha * 17) + jogador2.coluna;

    switch (tabuleiro_baixo1[jogador2.linha][jogador2.coluna]){
        case 0:
            tabuleiro_alto1 [posicao_array] = " * |";
            tabuleiro_baixo1 [jogador2.linha][jogador2.coluna] = 6;
            *pontuacao_j2 = *pontuacao_j2 + PONTUA_ERRO;
            break;
        case 2:
            tabuleiro_alto1 [posicao_array] = "P1 |";
            tabuleiro_baixo1[jogador2.linha][jogador2.coluna] = 6;
            *pontuacao_j2 = *pontuacao_j2 + PONTUA_P;
            *j2++;
            break;
        case 3:
            tabuleiro_alto1 [posicao_array] = "C1 |";
            tabuleiro_baixo1[jogador2.linha][jogador2.coluna] = 6;
            *pontuacao_j2 = *pontuacao_j2 + PONTUA_C;
            *j2++;        
            break;
        case 4:
            tabuleiro_alto1 [posicao_array] = "T1 |";
            tabuleiro_baixo1[jogador2.linha][jogador2.coluna] = 6;
            *pontuacao_j2 = *pontuacao_j2 + PONTUA_T;
            *j2++;
            break;
        case 5:
            tabuleiro_alto1 [posicao_array] = "H1 |";
            tabuleiro_baixo1[jogador2.linha][jogador2.coluna] = 6;
            *pontuacao_j2 = *pontuacao_j2 + PONTUA_H;
            *j2++;
            break;
        case 6:
            printf("Voce ja atirou nesse local! Tente novamente!\n");
            func_jogador2(tabuleiro_baixo1, tabuleiro_alto1, pontuacao_j2, j2, clock_inicial);
        }

    printar_tabuleiro(tabuleiro_alto1);
    printf("----------------------------------------------------------------------\n\n");

    if (*j2 == 84){
        printf("Parabens JOGADOR 2. Voce venceu!\n");
    }

    Sleep(2000);
}
// END AUX