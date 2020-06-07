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
#include "constants.h"

//FIM BIBLIOTECAS


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
int** alocar_tabuleiro_baixo ();
void free_tabuleiros (int** tabuleiro_baixo1, int** tabuleiro_baixo2, char **tabuleiro_alto1, char **tabuleiro_alto2);
void lateral_tabuleiro_alto (char** tabuleiro_alto);
char** design_tabuleiro_alto ();
void desenho_tabuleiro_alto (char** tabuleiro_alto);
void zerar_tabuleiros_baixos (int** tabuleiro_baixo1, int** tabuleiro_baixo2);
jogada pow ();
struct_relogio relogio (clock_t clock_inicial, struct_relogio addition);
void printar_jogador1(char** tabuleiro_alto2, int* pontuacao_j1, clock_t clock_inicial, struct_relogio addition);
void printar_jogador2(char** tabuleiro_alto1, int* pontuacao_j2, clock_t clock_inicial, struct_relogio addition);
bool func_jogador1(int** tabuleiro_baixo2, char** tabuleiro_alto2, int* pontuacao_j1, int* j1);
bool func_jogador2(int** tabuleiro_baixo1, char** tabuleiro_alto1, int* pontuacao_j2, int* j2, bool multi);
void gravar_jogo (int** tabuleiro_baixo1, int** tabuleiro_baixo2, int pontuacao_j1, int pontuacao_j2, int j1, int j2, struct_relogio tempo_jogo);
struct_relogio carregar_jogo (int** tabuleiro_baixo1, int** tabuleiro_baixo2, int* pontuacao_j1, int* pontuacao_j2, int* j1, int* j2);
void redesign_tabuleiro_alto (int** tabuleiro_baixo, char** tabuleiro_alto, int n);
void resetar_jogo (int** tabuleiro_baixo1, int** tabuleiro_baixo2, char** tabuleiro_alto1, char** tabuleiro_alto2, int* pontuacao_j1, int* pontuacao_j2, int* j1, int* j2);
// FIM DOS PRÓTOTIPOS


// MAIN FUNCTION

int main (){
    char opmenu [8][10] = {"RESET", "SAIR", "REGRAS", "MENU", "ACASO", "GRAVAR", "CARREGAR", "POW"};     //Declara as opções do menu
    char opcao_dig[10];                                                                                  //Opção digitada pelo usuário  

    bool bjogador1 = false;
    bool bjogador2 = false;
    bool win = false;
    bool multi;
    int j1, j2;
    int pontuacao_j1;
    int pontuacao_j2;
    
    clock_t clock_inicial;
    struct_relogio addition;
    addition.horas = 0;
    addition.minutos = 0;
    addition.segundos = 0;

    int** tabuleiro_baixo1 = alocar_tabuleiro_baixo();
    int** tabuleiro_baixo2 = alocar_tabuleiro_baixo();
    char** tabuleiro_alto1 = design_tabuleiro_alto();
    char** tabuleiro_alto2 = design_tabuleiro_alto();

    printf("----------------------------------------------- BATALHA NAVAL -------------------------------------------------\n\n");
    printf("Bem vindos a Batalha Naval!\n\n");
    printar_menu ();                                                                          //Chama a função menu()

    while(1){
        printf("Digite seu comando: ");
        scanf("%s", opcao_dig);                                                                    //Recebe a opção do jogador
        unsigned int tam = strlen(opcao_dig);
        char opcao[tam + 1];                                                                       //Declara uma variável que será utilizada para entrar nos laços do menu principal
        for (int i = 0; i <= tam; i++) opcao[i] = toupper(opcao_dig[i]);              
        
//Para evitar possíveis erros no programa, causados pela digitação de elementos com letras maiúsculas ou minúsculas, eleva-se todos os caracteres para letra maiuscula

//Início de um laço condicional para executar o comando digitado pelo usuário
//A função strcmp realiza uma comparação entra as strings do parâmetro, retornando o número 0 se elas forem iguais

        if (strcmp(opcao, opmenu[0]) == 0){
            int player;
            printf("Quantos players?             ----------------------------------------------------------------------------------\n");
            printf("(1) JOGADOR X COMPUTADOR                    \n");
            printf("(2) JOGADOR X JOGADOR                       \n");
            printf("OPCAO:   ");
            scanf("%d", &player);
            printf("---------------------------------------------------------------------------------------------------------------\n\n");

            switch (player){
                case 1:
                    multi = false;
                    break;
                case 2:
                    multi = true;
                    break;
                default:
                    printf("Opcao invalida! Digite RESET novamente para selecionar o número de players.");
                    multi = true;
                    break;
            }

            bjogador1 = true;
            clock_inicial = clock();

            resetar_jogo(tabuleiro_baixo1, tabuleiro_baixo2, tabuleiro_alto1, tabuleiro_alto2, &pontuacao_j1, &pontuacao_j2, &j1, &j2);
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
            Sleep(2000);
            return 0;
        }

        else if (strcmp(opcao, opmenu[2]) == 0) regras();                          //Exibe as regras pro usuário

        else if (strcmp(opcao, opmenu[3]) == 0) printar_menu();                    //Exibe o menu pro usuário

        else if (strcmp(opcao, opmenu[4]) == 0){
            zerar_tabuleiros_baixos (tabuleiro_baixo1, tabuleiro_baixo2);
            posicionar_armada(tabuleiro_baixo1, tabuleiro_baixo2);

            desenho_tabuleiro_alto(tabuleiro_alto1);
            desenho_tabuleiro_alto(tabuleiro_alto2);
        }

        else if (strcmp(opcao, opmenu[5]) == 0){
            gravar_jogo (tabuleiro_baixo1, tabuleiro_baixo2, pontuacao_j1, pontuacao_j2, j1, j2, relogio(clock_inicial, addition));
        }

        else if (strcmp(opcao, opmenu[6]) == 0){
            addition = carregar_jogo (tabuleiro_baixo1, tabuleiro_baixo2, &pontuacao_j1, &pontuacao_j2, &j1, &j2);
            redesign_tabuleiro_alto(tabuleiro_baixo1, tabuleiro_alto1, 1);
            redesign_tabuleiro_alto(tabuleiro_baixo2, tabuleiro_alto2, 2);
            bjogador1 = true;
            bjogador2 = false;
        }

        else if (strcmp(opcao, opmenu[7]) == 0){
            if (bjogador1 == true){
                win = func_jogador1 (tabuleiro_baixo2, tabuleiro_alto2, &pontuacao_j1, &j1);
                bjogador1 = false;
                bjogador2 = true;

                if (multi == false){
                    printar_jogador2(tabuleiro_alto1, &pontuacao_j2, clock_inicial, addition);
                    win = func_jogador2(tabuleiro_baixo1, tabuleiro_alto1, &pontuacao_j2, &j2, multi);
                    bjogador1 = true;
                    bjogador2 = false;
                }
            }
            else if (bjogador2 == true){
                win = func_jogador2(tabuleiro_baixo1, tabuleiro_alto1, &pontuacao_j2, &j2, multi);
                bjogador1 = true;
                bjogador2 = false;
            }
            else{
                printf("Inicie uma partida digitando RESET.\n");
            }
        }

        else printf("ERRO! Opcao invalida. Tente novamente!\n");            //Caso o usuário tenha digitado qualquer palavra diferente da indicada no menu, será demonstrada essa mensagem de erro

        if (bjogador1 == true){
            printar_jogador1(tabuleiro_alto2, &pontuacao_j1, clock_inicial, addition);
        }
        else if (bjogador2 == true){
            printar_jogador2(tabuleiro_alto1, &pontuacao_j2, clock_inicial, addition);
        }

        if (win == true){
            resetar_jogo (tabuleiro_baixo1, tabuleiro_baixo2, tabuleiro_alto1, tabuleiro_alto2, &pontuacao_j1, &pontuacao_j2, &j1, &j2);
            bjogador1 = false;
            bjogador2 = false;
            win = false;

            printf("\n\n");
            printar_menu();
        }
    }
    return 0;
}

// END MAIN


// AUX FUNCTIONS

void regras (){              
    printf("-------------------------------------------------- REGRAS -----------------------------------------------------\n");
    printf("- A armada completa sera composta por um porta-avioes (P) com 11 blocos, dois couracados (C) com 10 blocos,\ntres torpedeiros (T) com 7 blocos e quadro hidroavioes (H) com 8 blocos.\n");
    printf("- A sua armada sera posicionada aleatoriamente no seu campo de batalha.\n");
    printf("- Para atirar nos blocos do tabuleiro, voce devera digitar POW e a posicao que deseja atingir. \nPor exemplo, pow 15A atingira a bloco da linha 15, coluna A.\n");
    printf("- Ao atirar um bloco, voce podera atingir a agua, representada pelo *, ou um elemento da armada do seu oponente.\n");
    printf("Se voce atingir um porta-avioes (P), voce recebera 43 pontos; um couracado (C), voce recebera 78 pontos; um\ntorpedeiro (T), voce recebera 82 pontos; um hidroaviao (H), voce recebera 125 pontos, e se voce atigir a agua,\nvoce perdera 3 pontos\n");
    printf("- Para ganhar o jogo, voce devera afundar todos os navios do seu oponente.\n");
    printf("---------------------------------------------------------------------------------------------------------------\n\n");
}                            //end regras

void printar_menu (){                
    printf("--------------------------------------------------- MENU ------------------------------------------------------\n");
    printf("|Digite:                                                                                                      |\n");
    printf("|RESET - Iniciar uma nova partida.                                                                            |\n");
    printf("|SAIR - Abandonar o jogo, sem salvar.                                                                         |\n");
    printf("|REGRAS - Exibir as regras do jogo.                                                                           |\n");
    printf("|MENU - Exibir o menu do jogo.                                                                                |\n");
    printf("|ACASO - Iniciar um novo tabuleiro aleatorio, mas conserva seus pontos e o tempo no relogio.                  |\n");
    printf("|GRAVAR - Salvar o jogo em um arquivo com o nome tabuleiro-{timestamp}.txt.                                   |\n");
    printf("|CARREGAR {nome do arquivo} - Carregar o jogo que foi salvo.                                                  |\n");
    printf("|POW {posicao} - Atirar em um bloco                                                                           |\n");
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

void lateral_tabuleiro_alto (char** tabuleiro_alto){

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
    
}

char** design_tabuleiro_alto (){

    char **tabuleiro_alto = (char **) malloc (STRINGS * sizeof(char *));
    for(int i = 0; i < STRINGS; i++){
        tabuleiro_alto[i] = (char *) malloc (NUM_CHAR * sizeof(char));
    }

    lateral_tabuleiro_alto(tabuleiro_alto);
    desenho_tabuleiro_alto(tabuleiro_alto);

    return (tabuleiro_alto);
}

void desenho_tabuleiro_alto (char** tabuleiro_alto){
    int c = 17;

    for (int i = 17; i < STRINGS; i++){
        if (c == 17) c = 0;
        else {
            tabuleiro_alto[i] = "   |";
        }
        c++;
    }
}

void zerar_tabuleiros_baixos (int** tabuleiro_baixo1, int** tabuleiro_baixo2){
    for (int i = 0; i < LINHAS; i++){
        for (int j = 0; j < COLUNAS; j++){
            tabuleiro_baixo1[i][j] = 0;
            tabuleiro_baixo2[i][j] = 0;
        }
    }
}

jogada pow (){
    jogada coordenadas;
    char pow_in[4];

    char coordenadas_ins[4], letra;

    scanf("%s", coordenadas_ins);

    coordenadas.linha = atoi(coordenadas_ins);
    if (coordenadas.linha <= 0 || coordenadas.linha > 16){
        printf("ERRO! Posicao Invalida!\n");
        scanf("%s", pow_in);
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
                scanf("%s", pow_in);
                pow();
            }

        return (coordenadas);
    }
}

struct_relogio relogio (clock_t clock_inicial, struct_relogio addition){
    struct_relogio relogio;
    
    relogio.minutos = addition.minutos;
    relogio.horas = addition.horas;
    relogio.segundos = ((clock() - clock_inicial)/CLOCKS_PER_SEC) + addition.segundos;

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

void printar_jogador1 (char** tabuleiro_alto2, int* pontuacao_j1, clock_t clock_inicial, struct_relogio addition){
    struct_relogio tempo_jogo = relogio(clock_inicial, addition);

    printf("------------------------------ JOGADOR 1 -----------------------------\n\n");
    printf("%02lu: %02lu: %02lu                               Pontuacao: %d\n", tempo_jogo.horas, tempo_jogo.minutos, tempo_jogo.segundos, *pontuacao_j1);
    printar_tabuleiro(tabuleiro_alto2);
}

void printar_jogador2 (char** tabuleiro_alto1, int* pontuacao_j2, clock_t clock_inicial, struct_relogio addition){
    struct_relogio tempo_jogo = relogio(clock_inicial, addition);

    printf("------------------------------ JOGADOR 2 -----------------------------\n\n");
    printf("%02lu: %02lu: %02lu                               Pontuacao: %d\n", tempo_jogo.horas, tempo_jogo.minutos, tempo_jogo.segundos, *pontuacao_j2);
    printar_tabuleiro(tabuleiro_alto1);
}

bool func_jogador1(int** tabuleiro_baixo2, char** tabuleiro_alto2, int* pontuacao_j1, int* j1){
    
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
            tabuleiro_baixo2[jogador1.linha][jogador1.coluna] = 7;
            *pontuacao_j1 = *pontuacao_j1 + PONTUA_P;
            *j1 = *j1 + 1;
            break;
        case 3:
            tabuleiro_alto2 [posicao_array] = "C2 |";
            tabuleiro_baixo2[jogador1.linha][jogador1.coluna] = 8;
            *pontuacao_j1 = *pontuacao_j1 + PONTUA_C;
            *j1 = *j1 + 1;
            break;
        case 4:
            tabuleiro_alto2 [posicao_array] = "T2 |";
            tabuleiro_baixo2[jogador1.linha][jogador1.coluna] = 9;
            *pontuacao_j1 = *pontuacao_j1 + PONTUA_T;
            *j1 = *j1 + 1;
            break;
        case 5:
            tabuleiro_alto2 [posicao_array] = "H2 |";
            tabuleiro_baixo2[jogador1.linha][jogador1.coluna] = 10;
            *pontuacao_j1 = *pontuacao_j1 + PONTUA_H;
            *j1 = *j1 + 1;
            break;
        case 6:
            printf("Voce ja atirou nesse local! Tente novamente!\n");
            func_jogador1(tabuleiro_baixo2, tabuleiro_alto2, pontuacao_j1, j1);
        }

    printar_tabuleiro(tabuleiro_alto2);
    printf("----------------------------------------------------------------------\n\n");

    if (*j1 == 84){
        printf("Parabens JOGADOR 1. Voce venceu!\n");
        Sleep(2000);
        return true;
    }
    else{
        Sleep(2000);
        return false;
    }
}

bool func_jogador2(int** tabuleiro_baixo1, char** tabuleiro_alto1, int* pontuacao_j2, int* j2, bool multi){
    int posicao_array;
    jogada jogador2;

    if (multi == true){
        jogador2 = pow();                       // Essa função retorna uma struct com jogador2.linha e jogador2.coluna
    }
    else if (multi == false){
        srand (time(NULL));
        jogador2.coluna = 1 + rand () % 15;
        jogador2.linha = 1 + rand () % 15; 
    }
    posicao_array = (jogador2.linha * 17) + jogador2.coluna;

    switch (tabuleiro_baixo1[jogador2.linha][jogador2.coluna]){
        case 0:
            tabuleiro_alto1 [posicao_array] = " * |";
            tabuleiro_baixo1 [jogador2.linha][jogador2.coluna] = 6;
            *pontuacao_j2 = *pontuacao_j2 + PONTUA_ERRO;
            break;
        case 2:
            tabuleiro_alto1 [posicao_array] = "P1 |";
            tabuleiro_baixo1[jogador2.linha][jogador2.coluna] = 7;
            *pontuacao_j2 = *pontuacao_j2 + PONTUA_P;
            *j2 = *j2 + 1;
            break;
        case 3:
            tabuleiro_alto1 [posicao_array] = "C1 |";
            tabuleiro_baixo1[jogador2.linha][jogador2.coluna] = 8;
            *pontuacao_j2 = *pontuacao_j2 + PONTUA_C;
            *j2 = *j2 + 1;       
            break;
        case 4:
            tabuleiro_alto1 [posicao_array] = "T1 |";
            tabuleiro_baixo1[jogador2.linha][jogador2.coluna] = 9;
            *pontuacao_j2 = *pontuacao_j2 + PONTUA_T;
            *j2 = *j2 + 1;
            break;
        case 5:
            tabuleiro_alto1 [posicao_array] = "H1 |";
            tabuleiro_baixo1[jogador2.linha][jogador2.coluna] = 10;
            *pontuacao_j2 = *pontuacao_j2 + PONTUA_H;
            *j2 = *j2 + 1;
            break;
        case 6:
            printf("Voce ja atirou nesse local! Tente novamente!\n");
            func_jogador2(tabuleiro_baixo1, tabuleiro_alto1, pontuacao_j2, j2, multi);
        }

    printar_tabuleiro(tabuleiro_alto1);
    printf("----------------------------------------------------------------------\n\n");

    if (*j2 == 84){
        printf("Parabens JOGADOR 2. Voce venceu!\n");
        Sleep(2000);
        return true;
    }
    else{
        Sleep(2000);
        return false;
    }
}

void gravar_jogo (int** tabuleiro_baixo1, int** tabuleiro_baixo2, int pontuacao_j1, int pontuacao_j2, int j1, int j2, struct_relogio tempo_jogo){
    char name[50];
    int c = 0;
    sprintf(name, "tabuleiro%lu.txt", time(NULL));

    FILE* arquivo = fopen(name, "w");
    fprintf(arquivo, "%lu:%lu:%lu\n", tempo_jogo.horas, tempo_jogo.minutos, tempo_jogo.segundos);
    fprintf(arquivo, "%d %d\n", pontuacao_j1, j1);
    fprintf(arquivo, "%d %d\n", pontuacao_j2, j2);

    for (int i = 0; i < LINHAS; i++){
        for (int j = 0; j < COLUNAS; j++){
            if (j == (COLUNAS - 1)) fprintf(arquivo, "%d\n", tabuleiro_baixo1[i][j]);
            else fprintf(arquivo, "%d ", tabuleiro_baixo1[i][j]);
        }
    }
    for (int i = 0; i < LINHAS; i++){
        for (int j = 0; j < COLUNAS; j++){
            if (j == (COLUNAS - 1)) fprintf(arquivo, "%d\n", tabuleiro_baixo2[i][j]);
            else fprintf(arquivo, "%d ", tabuleiro_baixo2[i][j]);
        }
    }

    fclose(arquivo);
}

struct_relogio carregar_jogo (int** tabuleiro_baixo1, int** tabuleiro_baixo2, int* pontuacao_j1, int* pontuacao_j2, int* j1, int* j2){
    char file_name[50];
    int c = 0;
    struct_relogio tempo_jogo;
    
    scanf("%s", file_name);
    fflush(stdin);

    FILE* arquivo = fopen(file_name, "r");

    if (arquivo == NULL){
        printf("ERRO na abertura do arquivo.\n");
    }
    else{
        fscanf(arquivo, "%lu:%lu:%lu\n", &tempo_jogo.horas, &tempo_jogo.minutos, &tempo_jogo.segundos);
        fscanf(arquivo, "%d %d\n", pontuacao_j1, j1);
        fscanf(arquivo, "%d %d\n", pontuacao_j2, j2);

        for (int i = 0; i < LINHAS; i++){
            for (int j = 0; j < COLUNAS; j++){
                if (j == (COLUNAS - 1)) fscanf(arquivo, "%d\n", &tabuleiro_baixo1[i][j]);
                else fscanf(arquivo, "%d ", &tabuleiro_baixo1[i][j]);
            }
        }
        for (int i = 0; i < LINHAS; i++){
            for (int j = 0; j < COLUNAS; j++){
                if (j == (COLUNAS - 1)) fscanf(arquivo, "%d\n", &tabuleiro_baixo2[i][j]);
                else fscanf(arquivo, "%d ", &tabuleiro_baixo2[i][j]);
            }
        }

        fclose(arquivo);
        return tempo_jogo;
    }
}

void redesign_tabuleiro_alto (int** tabuleiro_baixo, char** tabuleiro_alto, int n){
    int posicao_array;

    for (int i = 0; i < LINHAS; i++){
        for (int j = 0; j < COLUNAS; j++){
            posicao_array = (i * 17) + j;
            if (tabuleiro_baixo[i][j] == 0 || tabuleiro_baixo[i][j] == 2 || tabuleiro_baixo[i][j] == 3 || tabuleiro_baixo[i][j] == 4 || tabuleiro_baixo[i][j] == 5){
                tabuleiro_alto[posicao_array] = "   |";
            }
            else{
                switch (tabuleiro_baixo[i][j]){
                    case 6:
                        tabuleiro_alto[posicao_array] = " * |";
                        break;
                    case 7:
                        if (n == 1){
                            tabuleiro_alto[posicao_array] = "P1 |";
                        } 
                        else if (n == 2) {
                            tabuleiro_alto[posicao_array] = "P2 |";
                        }
                        break;
                    case 8:
                        if (n == 1){ 
                            tabuleiro_alto[posicao_array] = "C1 |";
                        }
                        else if (n == 2) {
                            tabuleiro_alto[posicao_array] = "C2 |";
                        }
                        break;
                    case 9:
                        if (n == 1) {
                            tabuleiro_alto[posicao_array] = "T1 |";
                        }
                        else if (n == 2) {
                            tabuleiro_alto[posicao_array] = "T2 |";
                        }
                        break;
                    case 10:
                        if (n == 1) {
                            tabuleiro_alto[posicao_array] = "H1 |";
                        }
                        else if (n == 2) {
                            tabuleiro_alto[posicao_array] = "H2 |";
                        }
                        break;
                }
            }
        }
    }
    lateral_tabuleiro_alto(tabuleiro_alto);
}

void resetar_jogo (int** tabuleiro_baixo1, int** tabuleiro_baixo2, char** tabuleiro_alto1, char** tabuleiro_alto2, int* pontuacao_j1, int* pontuacao_j2, int* j1, int* j2){
    zerar_tabuleiros_baixos(tabuleiro_baixo1, tabuleiro_baixo2);

    lateral_tabuleiro_alto(tabuleiro_alto1);
    lateral_tabuleiro_alto(tabuleiro_alto2);
    desenho_tabuleiro_alto(tabuleiro_alto1);
    desenho_tabuleiro_alto(tabuleiro_alto2);

    *j1 = 0;
    *j2 = 0;
    *pontuacao_j1 = 0;
    *pontuacao_j2 = 0;
}

// END AUX