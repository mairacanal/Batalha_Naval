/* BATALHA NAVAL
Desenvolvido por Maíra Canal e Caroline Grupe

Objetivo: Desenvolver um jogo multiplayer de Batalha Naval em linguagem C
USP - ICC1 - 2020
*/

// BIBLIOTECAS

#include "lib_naval.h"
#include "constants.h"

//FIM BIBLIOTECAS

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
    int player;
    
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
            addition.horas = 0;
            addition.minutos = 0;
            addition.segundos = 0;


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

        else if (strcmp(opcao, opmenu[2]) == 0) printar_regras();                  //Exibe as regras pro usuário

        else if (strcmp(opcao, opmenu[3]) == 0) printar_menu();                    //Exibe o menu pro usuário

        else if (strcmp(opcao, opmenu[4]) == 0){
            zerar_tabuleiros_baixos (tabuleiro_baixo1, tabuleiro_baixo2);
            posicionar_armada(tabuleiro_baixo1, tabuleiro_baixo2);

            desenho_tabuleiro_alto(tabuleiro_alto1);
            desenho_tabuleiro_alto(tabuleiro_alto2);
        }

        else if (strcmp(opcao, opmenu[5]) == 0){
            gravar_jogo (tabuleiro_baixo1, tabuleiro_baixo2, pontuacao_j1, pontuacao_j2, j1, j2, multi, relogio(clock_inicial, addition));
        }

        else if (strcmp(opcao, opmenu[6]) == 0){
            addition = carregar_jogo (tabuleiro_baixo1, tabuleiro_baixo2, &pontuacao_j1, &pontuacao_j2, &j1, &j2, &player);
            switch (player){
                case 1:
                    multi = false;
                    break;
                case 2:
                    multi = true;
                    break;
            }
            redesign_tabuleiro_alto(tabuleiro_baixo1, tabuleiro_alto1, 1);
            redesign_tabuleiro_alto(tabuleiro_baixo2, tabuleiro_alto2, 2);
            bjogador1 = true;
            bjogador2 = false;
            clock_inicial = clock();
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
