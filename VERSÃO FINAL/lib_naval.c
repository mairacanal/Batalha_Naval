#include "lib_naval.h"
#include "constants.h"

// FUNÇÕES PRIVADAS (utilizadas para auxiliar na construção do código) --------------------

void portaavioes (int** tabuleiro_baixo){
    int linhaP, colunaP;

    // Geração de um centro aleatório para a embarcação
    srand(time(NULL)*time(NULL));
    linhaP = 2 + (rand() % 12);
    srand(time(NULL));
    colunaP = 3 + (rand() % 11);

    // Posicionamento da embarcação no tabuleiro "back-end"
    for (int i = (colunaP - 2); i <= (colunaP + 2); i++) tabuleiro_baixo[linhaP][i] = 2;
    for (int j = (linhaP - 1); j <= (linhaP + 2); j++) {
        tabuleiro_baixo[j][colunaP - 1] = 2;
        tabuleiro_baixo[j][colunaP + 1] = 2;
    }
}

/*
Cabeçalho: void portaavioes (int**)

Argumentos: recebe como argumento o tabuleiro "back-end" do jogador

Objetivo: Posicionar o porta-aviões no tabuleiro do jogador. No tabuleiro "back-end", o porta-aviões é representado
pelo número 2 ("dois"). A função rand() gera um centro (representado pelo bloco rosa no documento Excel) aleatório 
para o porta-aviões, de forma a possibilitar o posicionamento da embarcação.
*/

void couracados (int** tabuleiro_baixo){
    int linhaC, colunaC;

    // Geração de um centro aleatório para a embarcação
    // O uso do laço "do while" impede que uma embarcação seja posicionada por cima de outra
    do{
        srand(time(NULL)*time(NULL));
        linhaC = 3 + (rand() % 10);
        srand(time(NULL));
        colunaC = 3 + (rand() % 11);
    } while (tabuleiro_baixo[linhaC][colunaC - 2] != 0 || tabuleiro_baixo[linhaC][colunaC - 1] != 0 || tabuleiro_baixo[linhaC][colunaC] != 0 || tabuleiro_baixo[linhaC][colunaC + 1] != 0 || tabuleiro_baixo[linhaC][colunaC + 2] != 0 || tabuleiro_baixo[linhaC - 2][colunaC + 1] != 0 || tabuleiro_baixo[linhaC - 1][colunaC + 1] != 0 || tabuleiro_baixo[linhaC + 1][colunaC - 1] != 0 || tabuleiro_baixo[linhaC + 2][colunaC - 1] != 0 || tabuleiro_baixo[linhaC + 3][colunaC - 1] != 0);   
    
    // Posicionamento da embarcação no tabuleiro "back-end"
    for (int i = (colunaC - 2); i <= (colunaC + 2); i++) tabuleiro_baixo[linhaC][i] = 3;
    for (int j = (linhaC - 2); j < linhaC; j++) tabuleiro_baixo[j][colunaC + 1] = 3;
    for (int j = (linhaC + 1); j <= (linhaC + 3); j++) tabuleiro_baixo[j][colunaC - 1] = 3;
}

/*
Cabeçalho: void couracados (int**)

Argumentos: recebe como argumento o tabuleiro "back-end" do jogador

Objetivo: Posicionar o couraçado no tabuleiro do jogador. No tabuleiro "back-end", o couraçado é representado
pelo número 3 ("três"). A função rand() gera um centro (representado pelo bloco rosa no documento Excel) aleatório 
para o couraçado, de forma a possibilitar o posicionamento da embarcação.
*/

void torpedeiros (int** tabuleiro_baixo){
    int linha, coluna;

    // Geração de um centro aleatório para a embarcação
    // O uso do laço "do while" impede que uma embarcação seja posicionada por cima de outra
    do{
        srand(time(NULL)*time(NULL));
        linha = 2 + (rand() % 13);
        srand(time(NULL));
        coluna = 2 + (rand() % 13);
    }while(tabuleiro_baixo[linha][coluna] != 0 || tabuleiro_baixo[linha][coluna - 1] != 0 || tabuleiro_baixo[linha][coluna + 1] != 0 || tabuleiro_baixo[linha - 1][coluna] != 0 || tabuleiro_baixo[linha - 1][coluna + 1] != 0 || tabuleiro_baixo[linha + 1][coluna - 1] != 0 || tabuleiro_baixo[linha + 1][coluna] != 0);
    
    // Posicionamento da embarcação no tabuleiro "back-end"
    for (int j = coluna; j <= (coluna + 1); j++) tabuleiro_baixo[linha - 1][j] = 4;
    for (int j = (coluna - 1); j <= (coluna + 1); j++) tabuleiro_baixo[linha][j] = 4;
    for (int j = (coluna - 1); j <= coluna; j++) tabuleiro_baixo[linha + 1][j] = 4;
}

/*
Cabeçalho: void torpedeiros (int**)

Argumentos: recebe como argumento o tabuleiro "back-end" do jogador

Objetivo: Posicionar o torpedeiro no tabuleiro do jogador. No tabuleiro "back-end", o torpedeiro é representado
pelo número 4 ("quatro"). A função rand() gera um centro (representado pelo bloco rosa no documento Excel) aleatório 
para o torpedeiro, de forma a possibilitar o posicionamento da embarcação.
*/

void hidroavioes (int** tabuleiro_baixo){
    int linha, coluna;

    // Geração de um centro aleatório para a embarcação
    // O uso do laço "do while" impede que uma embarcação seja posicionada por cima de outra
    do{
        srand(time(NULL)*time(NULL));
        linha = 1 + (rand() % 14);
        srand(time(NULL));
        coluna = 5 + (rand() % 8);
    }while(tabuleiro_baixo[linha][coluna - 4] != 0 || tabuleiro_baixo[linha][coluna - 2] != 0 || tabuleiro_baixo[linha][coluna] != 0 || tabuleiro_baixo[linha][coluna + 2] != 0 || tabuleiro_baixo[linha + 1][coluna - 3] != 0 || tabuleiro_baixo[linha + 1][coluna - 1] != 0 || tabuleiro_baixo[linha + 1][coluna + 1] != 0 || tabuleiro_baixo[linha + 1][coluna + 3] != 0);
    
    // Posicionamento da embarcação no tabuleiro "back-end"
    for (int j = (coluna - 4); j <= (coluna + 2); j = (j + 2)) tabuleiro_baixo[linha][j] = 5;
    for (int j = (coluna - 3); j <= (coluna + 3); j = (j + 2)) tabuleiro_baixo[linha + 1][j] = 5;
}

/*
Cabeçalho: void hidroavioes (int**)

Argumentos: recebe como argumento o tabuleiro "back-end" do jogador

Objetivo: Posicionar o hidroavião no tabuleiro do jogador. No tabuleiro "back-end", o hidroavião é representado
pelo número 5 ("cinco"). A função rand() gera um centro (representado pelo bloco rosa no documento Excel) aleatório 
para o hidroavião, de forma a possibilitar o posicionamento da embarcação.
*/

// FIM FUNÇÕES PRIVADAS -------------------------------------------------------------------

// FUNÇÕES PÚBLICAS -----------------------------------------------------------------------

void posicionar_armada (int** tabuleiro_baixo1, int** tabuleiro_baixo2){

    //Posicionamento dos porta-aviões(P) no tabuleiro do jogador 1
    portaavioes (tabuleiro_baixo1);

    //Posicionamento dos couraçados (C) no tabuleiro do jogador 1
    for (int i = 1; i <= NUM_COURACADOS; i++){
        couracados(tabuleiro_baixo1);
    }

    //Posicionamento dos torpedeiros (T) no tabuleiro do jogador 1
    for (int i = 1; i <= NUM_TORPEDEIROS; i++){
        torpedeiros(tabuleiro_baixo1);
    }

    //Posicionamento dos hidroaviões (H) no tabuleiro do jogador 1
    for (int i = 1; i <= NUM_HIDROAVIOES; i++){
        hidroavioes(tabuleiro_baixo1);
    }

    //Posicionamento dos porta-aviões(P) no tabuleiro do jogador 2
    portaavioes (tabuleiro_baixo2);

    //Posicionamento dos couraçados (C) no tabuleiro do jogador 2
    for (int i = 1; i <= NUM_COURACADOS; i++){
        couracados(tabuleiro_baixo2);
    }

    //Posicionamento dos torpedeiros (T) no tabuleiro do jogador 2
    for (int i = 1; i <= NUM_TORPEDEIROS; i++){
        torpedeiros(tabuleiro_baixo2);
    }

    //Posicionamento dos hidroaviões (H) no tabuleiro do jogador 2
    for (int i = 1; i <= NUM_HIDROAVIOES; i++){
        hidroavioes(tabuleiro_baixo2);
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

void printar_regras (){              
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

char** design_tabuleiro_alto (){

    char **tabuleiro_alto = (char **) malloc (STRINGS * sizeof(char *));
    for(int i = 0; i < STRINGS; i++){
        tabuleiro_alto[i] = (char *) malloc (NUM_CHAR * sizeof(char));
    }

    lateral_tabuleiro_alto(tabuleiro_alto);
    desenho_tabuleiro_alto(tabuleiro_alto);

    return (tabuleiro_alto);
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
        default:
            printf("Voce ja atirou nesse local! Tente novamente!\n");
            func_jogador1(tabuleiro_baixo2, tabuleiro_alto2, pontuacao_j1, j1);
        }

    printf("----------------------------------------------------------------------\n\n");
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
        default:
            printf("Voce ja atirou nesse local! Tente novamente!\n");
            func_jogador2(tabuleiro_baixo1, tabuleiro_alto1, pontuacao_j2, j2, multi);
        }

    printf("----------------------------------------------------------------------\n\n");
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

void gravar_jogo (int** tabuleiro_baixo1, int** tabuleiro_baixo2, int pontuacao_j1, int pontuacao_j2, int j1, int j2, bool multi, struct_relogio tempo_jogo){
    char name[50];
    int c = 0;
    sprintf(name, "tabuleiro%lu.txt", time(NULL));

    FILE* arquivo = fopen(name, "w");
    fprintf(arquivo, "%lu:%lu:%lu\n", tempo_jogo.horas, tempo_jogo.minutos, tempo_jogo.segundos);
    fprintf(arquivo, "%d %d\n", pontuacao_j1, j1);
    fprintf(arquivo, "%d %d\n", pontuacao_j2, j2);
    if (multi == false){
        fprintf(arquivo, "1\n");
    }
    else if (multi == true){
        fprintf(arquivo, "2\n");
    }

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

struct_relogio carregar_jogo (int** tabuleiro_baixo1, int** tabuleiro_baixo2, int* pontuacao_j1, int* pontuacao_j2, int* j1, int* j2, int* player){
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
        fscanf(arquivo, "%d\n", player);

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

// FIM FUNÇÕES PÚBLICAS -------------------------------------------------------------------