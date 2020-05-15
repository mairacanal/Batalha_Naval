/* BATALHA NAVAL
Desenvolvido por Maíra Canal e Caroline Grupe

Objetivo: Desenvolver um jogo multiplayer de Batalha Naval em linguagem C
USP - ICC1 - 2020
*/

#include <stdio.h>              //Biblioteca padrão
#include <ctype.h>              //Biblioteca para usar o toupper()
#include <string.h>             //Biblioteca para manipular strings

// PRÓTOTIPOS
void regras ();
void menu ();
// FIM DOS PRÓTOTIPOS

// MAIN FUNCTION

int main (){
    char opmenu [7][10] = {"RESET", "SAIR", "REGRAS", "MENU", "ACASO", "GRAVAR", "CARREGAR"};    //Declara as opções do menu
    char opcao_dig[10];                                                                           //Opção digitada pelo usuário
    long int tam;                                                                                 //Tamanho da opção digitada pelo usuário

    printf("----------------------------------------------- BATALHA NAVAL -------------------------------------------------\n\n");
    printf("Bem vindos a Batalha Naval!\n\n");
    menu ();                                   //Chama a função menu()
    while(1){
        scanf("%s", opcao_dig);                                                       //Recebe a opção do jogador
        tam = strlen(opcao_dig);                                                      //Determina o tamanho da string digitada pelo usuário
        char opcao[tam + 1];                                                          //Declara uma variável que será utilizada para entrar nos laços do menu principal
        for (int i = 0; i <= tam; i++) opcao[i] = toupper(opcao_dig[i]);              
        
//Para evitar possíveis erros no programa, causados pela digitação de elementos com letras maiúsculas ou minúsculas, eleva-se todos os caracteres para letra maiuscula
//Início de um laço condicional para executar o comando digitado pelo usuário

        if (strcmp(opcao, opmenu[0]) == 0){

        }
        else if (strcmp(opcao, opmenu[1]) == 0){

        }
        else if (strcmp(opcao, opmenu[2]) == 0) regras();                  //Exibe as regras pro usuário
        else if (strcmp(opcao, opmenu[3]) == 0) menu();                    //Exibe o menu pro usuário
        else if (strcmp(opcao, opmenu[4]) == 0){

        }
        else if (strcmp(opcao, opmenu[5]) == 0){

        }
        else if (strcmp(opcao, opmenu[6]) == 0){

        }
        else printf("ERRO! Opcao invalida. Tente novamente!\n");            //Caso o usuário tenha digitado qualquer palavra diferente da indicada no menu, será demonstrada essa mensagem de erro
    }
    return 0;
}

// END MAIN

// AUX FUNCTIONS
void regras (){              //Função auxiliar para chamar as regras do jogo
    printf("---------------------------------------------------- REGRAS -------------------------------------------------------\n");
    printf(" - A armada completa sera composta por um porta-avioes (P) com 11 blocos, dois couracados (C) com 10 blocos,\ntres torpedeiros (T) com 7 blocos e quadro hidroavioes (H) com 8 blocos.\n");
    printf(" - A sua armada sera posicionada aleatoriamente no seu campo de batalha.\n");
    printf(" - Para atirar nos blocos do tabuleiro, voce devera digitar POW e a posicao que deseja atingir. \nPor exemplo, pow 15A atingira a bloco da linha 15, coluna A.\n");
    printf(" - Se voce atingir um porta-avioes (P), voce recebera 43 pontos; um couracado (C), voce recebera 78 pontos; um\ntorpedeiro (T), voce recebera 82 pontos; um hidroaviao (H), voce recebera 125 pontos, e se voce atigir a agua,\nvoce perdera 3 pontos\n");
    printf(" - Ao atirar um bloco, voce podera atingir a agua, representada pelo *, ou um elemento da armada do seu oponente.\n");
    printf(" - Para ganhar o jogo, voce devera afundar todos os navios do seu oponente.\n");
    printf("-------------------------------------------------------------------------------------------------------------------\n\n");
}                            //end regras

void menu (){                //Função auxiliar para chamar o menu do jogo
    printf("--------------------------------------------------- MENU ------------------------------------------------------\n");
    printf("Digite:\n");
    printf("RESET - Iniciar uma nova partida.\n");
    printf("SAIR - Abandonar o jogo, sem salvar.\n");
    printf("REGRAS - Exibir as regras do jogo.\n");
    printf("MENU - Exibir o menu do jogo.\n");
    printf("ACASO - Iniciar um novo tabuleiro aleatorio, mas conserva seus pontos e o tempo no relogio.\n");
    printf("GRAVAR - Salvar o jogo em um arquivo com o nome tabuleiro-{timestamp}.txt.\n");
    printf("CARREGAR {nome do arquivo} - Carregar o jogo que foi salvo.\n");
    printf("---------------------------------------------------------------------------------------------------------------\n\n");
}                            //end menu

// END AUX
