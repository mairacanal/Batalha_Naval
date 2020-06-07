/* BIBLIOTECA BATALHA NAVAL
Desenvolvido por Maíra Canal e Caroline Grupe

Objetivo: Criar funções auxiliares para facilitar o desenvolvimento da Batalha Naval e facilitar o entendimento
do código principal do jogo.

USP - ICC1 - 2020
*/


#include <_mingw.h>                        // Biblioteca padrão utilizada para auxiliar na compilação do código
                                           // no Windows         

#ifndef LIB_NAVAL_H_                       
#define LIB_NAVAL_H_
#pragma GCC system_header

_CRTIMP __cdecl __MINGW_NOTHROW void posicionar_armada (int** , int** );   

/*
Cabeçalho: void posicionar_armada (int** , int**)

Argumentos: o primeiro argumento deve consistir em uma matriz 17x17, referente ao tabuleiro "back-end" do jogador
1 e o segundo argumento deve consistir em uma matriz 17x17, referente ao tabuleiro "back-end" do jogador 2.

Objetivo: Posicionar a armada do jogador 1 e do jogador 2 de forma aleatória, seguindo os designs de embarcação
disponibilizados em: https://docs.google.com/spreadsheets/d/1WBbv69VxdggPeCLtptqalj6iOX6eftSXgL8V4Xe4kGc/edit?usp=sharing
(acesso permitido para o domínio Universidade de São Paulo). Nesse arquivo em Excel, é possível ver, em rosa, 
o centro da embarcação, elemento essencial para a construção das embarcações.
*/

_CRTIMP __cdecl __MINGW_NOTHROW void printar_tabuleiro (char** );

/*
Cabeçalho: void printar_tabuleiro (char** )

Argumentos: recebe como argumento o tabuleiro "front-end" do jogador

Objetivo: imprime o tabuleiro "front-end" do jogador no terminal. O tabuleiro "front-end" tem o seguinte modelo:

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

Sendo preenchido de acordo com as orientações do professor.
*/

_CRTIMP __cdecl __MINGW_NOTHROW void printar_regras ();

/*
Cabeçalho: void printar_regrar()

Argumentos: Não há argumentos.

Objetivo: Imprimir, na tela do usuário, as regras.

Retorno: Não há retorno.
*/

_CRTIMP __cdecl __MINGW_NOTHROW void printar_menu ();

/*
Cabeçalho: void printar_menu()

Argumentos: Não há argumentos.

Objetivo: Imprimir, na tela do usuário, o menu.

Retorno: Não há retorno.
*/

_CRTIMP __cdecl __MINGW_NOTHROW int** alocar_tabuleiro_baixo ();

/*
Cabeçalho: int** alocar_tabuleiro_baixo()

Argumentos: não há argumentos.

Objetivo: Fazer a alocação de memória heap para uma matriz 17x17 e atribuir 0 a todos os bytes alocados (função calloc), 
a essa matriz foi dado o nome de tabuleiro_baixo (referente ao tabuleiro "back-end").

Retorno: Retorna uma matriz 17x17, referente ao tabuleiro_baixo de um dos jogadores.
*/

_CRTIMP __cdecl __MINGW_NOTHROW void free_tabuleiros (int** , int** , char **, char **);

/*
Cabeçalho: void free_tabuleiros (int** , int** , char **, char **)

Argumentos: As duas matrizes 17x17 criadas e alocadas,"tabuleiro_baixo" e os dois vetores de string criados e alocados, "tabuleiro_alto".

Objetivo: Desalocar a memória de cada uma dessas matrizes.

Retorno: Não há retorno.
*/

_CRTIMP __cdecl __MINGW_NOTHROW void lateral_tabuleiro_alto (char** );

/*
Cabeçalho: void lateral_tabuleiro_alto (char** )

Argumentos: Vetor de strings, referente ao tabuleiro_alto do jogador (tabuleiro "front-end").

Objetivo: Definir as strings em cada elemento do vetor determinadas pela primeira linha (que contém as letras de A a P) e pela primeira 
coluna (que contém os números de 1 a 16) do tabuleiro de cada jogador da batalha naval.

Retorno: Não há retorno.
*/

_CRTIMP __cdecl __MINGW_NOTHROW void desenho_tabuleiro_alto (char** );

/*
Cabeçalho: void desenho_tabuleiro_alto (char** )

Argumentos: Vetor de strings, referente ao tabuleiro_alto do jogador (tabuleiro "front-end").

Objetivo: Preenche o vetor interior de strings com a seguinte string: "    |"

Retorno: Não há retorno.
*/

_CRTIMP __cdecl __MINGW_NOTHROW char** design_tabuleiro_alto ();

/*
Cabeçalho: char** design_tabuleiro_alto ()

Argumentos: Não há argumentos.

Objetivo: Alocar memória para um vetor de strings com 289 strings (17x17), referente ao "tabuleiro_alto", e preenchê-lo com o design 
escolhido para o tabuleiro, utilizando as funções desenho_tabuleiro_alto (char** ) e design_tabuleiro_alto (). 

Retorno: Retorna o tabuleiro_alto.
*/


_CRTIMP __cdecl __MINGW_NOTHROW void zerar_tabuleiros_baixos (int** , int** );

/*
Cabeçalho: void zerar_tabuleiros_baixos (int** , int** )

Argumentos: Duas matrizes 17x17, referentes aos tabuleiros baixos dos jogadores 1 e 2.

Objetivo: Colocar 0 em todos os espaços alocados para essas matrizes.

Retorno: Não há retorno.
*/

_CRTIMP __cdecl __MINGW_NOTHROW jogada pow ();

/*
Cabeçalho: jogada pow ()

Argumentos: Não há argumentos.

Objetivo: Recebe as coordenadas digitadas pelo usuário para transformá-las em coordenadas númericas que possam ser utilizadas para a 
identificar essa posição no tabuleiro baixo.

Retorno: Struct "jogada", que contem os valores da linha e da coluna que o usuário escolheu para atingir.
*/

_CRTIMP __cdecl __MINGW_NOTHROW struct_relogio relogio (clock_t , struct_relogio );

/*
Cabeçalho: struct_relogio relogio (clock_t , struct_relogio )

Argumentos: long "clock_t" que contem o clock do momento em que o jogador iniciou o jogo e uma struct "struct_relogio" que adiciona o tempo
de execução de jogo, em casos de jogos carregados.

Objetivo: determinar o tempo de jogo, por meio da variação do clock entre o momento inicial e o momento atual. Em caso de jogos carregados,
adiciona o tempo prévio de execução.

Retorno: Struct "struct_relogio" com o valor de segundos, minutos e horas.
*/

_CRTIMP __cdecl __MINGW_NOTHROW void printar_jogador1(char** , int* , clock_t , struct_relogio );

/*
Cabeçalho: void printar_jogador1(char** , int* , clock_t , struct_relogio )

Argumentos: Vetor de strings do jogador 2 ("tabuleiro_alto2"), pontuação do jogador 1, long "clock_t" que armazena o tempo inicial de jogo  e 
a struct "struct_relogio" que adiciona o tempo prévio de execução, em caso de jogos carregados.

Objetivo: Essa função imprime a tela do jogador 1, de forma a imprimir o tabuleiro "front end" do jogador 2, por meio da função printar_tabuleiro()
a pontuação do jogador 1 e o tempo de jogo nesse momento. 

Retorno: Não há retorno.
*/

_CRTIMP __cdecl __MINGW_NOTHROW void printar_jogador2(char** , int* , clock_t , struct_relogio );

/*
Cabeçalho: void printar_jogador2(char** , int* , clock_t , struct_relogio )

Argumentos: Vetor de strings do jogador 1 ("tabuleiro_alto1"), pontuação do jogador 2, long "clock_t" que armazena o tempo inicial de jogo  e 
a struct "struct_relogio" que adiciona o tempo prévio de execução, em caso de jogos carregados.

Objetivo: Essa função imprime a tela do jogador 2, de forma a imprimir o tabuleiro "front end" do jogador 1, por meio da função printar_tabuleiro()
a pontuação do jogador 2 e o tempo de jogo nesse momento. 

Retorno: Não há retorno.
*/

_CRTIMP __cdecl __MINGW_NOTHROW bool func_jogador1(int** , char** , int* , int* );

/*
Cabeçalho: bool func_jogador1(int** , char** , int* , int* );

Argumentos: Matriz 17x17 do jogador 2, referente ao tabuleiro "back-end", vetor de strings do jogador 2, referente ao tabueleiro "front-end", 
ponteiro para a variável de pontuação do jogador 1 e ponteiro para a variável que armazena o número de acertos do jogador 1.

Objetivo: Calcular a pontuação do jogador 1. A pontuação do jogador 1 varia a cada jogada. Ela recebe um valor específico dependendo da peça 
que o jogador atingiu e perde um certo valor quando ele atinge a água. As MACROS que definem esses valores estão declaradas na biblioteca 
"constants.h". O valor de "j1" aumenta em 1 cada vez que o jogador acerta o ataque em alguma peça.

Retorno: Retorna uma variável booleana, sendo essa "true" se o valor da variável "j1" do jogador 1 chegar a 84 e "false" se não. Essa variável
aponta se o jogador ganhou o jogo, isto é, acertou todas as posições de todas as embarcações.
*/

_CRTIMP __cdecl __MINGW_NOTHROW bool func_jogador2(int** , char** , int* , int* , bool );

/*
Cabeçalho: bool func_jogador2(int** , char** , int* , int* , bool )

Argumentos: Matriz 17x17 do jogador 1, referente ao tabuleiro "back-end", vetor de strings do jogador 1, referente ao tabueleiro "front-end",
ponteiro para a variável de pontuação do jogador 1, ponteiro para a variável que armazena o número de acertos do jogador 1 e uma variável
booleana que aponta se o jogo está no modo single ou multiplayer.

Objetivo: Caso a variável booleana seja "false", indica que o jogo está no modo "JOGADOR X COMPUTADOR". Nesse modo, essa função gera dois números
aleatórios entre 1 e 16, referentes a linha e a coluna da jogada. Caso a variável booleana seja "true", indica que o jogo está no modo "JOGADOR X
JOGADOR". Nesse modo, essa função recebe as coordenadas númeras do disparo do jogador e realiza a correspondência entre o tabuleiro alto e o 
tabuleiro baixo. Além disso, calcular a pontuação do jogador 2, a qual varia a cada jogada. Ela recebe um valor específico dependendo da peça 
que o jogador atingiu e perde um certo valor quando ele atinge a água. As MACROS que definem esses valores estão declaradas na biblioteca 
"constants.h". O valor de "j2" aumenta em 1 cada vez que o jogador acerta o ataque em alguma peça.


Retorno: Retorna uma variável booleana, sendo essa "true" se o valor da variável "j2" do jogador 2 chegar a 84 e "false" se não. Essa variável
aponta se o jogador ganhou o jogo, isto é, acertou todas as posições de todas as embarcações.
*/

_CRTIMP __cdecl __MINGW_NOTHROW void gravar_jogo (int** , int** , int , int , int , int , bool , struct_relogio );

/*
Cabeçalho: void gravar_jogo (int** , int** , int , int , int , int , bool , struct_relogio )

Argumentos: Matriz 17x17 do jogador 1 e 2, referente aos tabuleiros "back end" dos jogadores, variável com pontuação do jogador 1 e 2, variável 
com o número de acertos do jogador 1 e 2, uma variável booleana que aponta se o jogo está no modo multiplayer ou singleplayer e a struct 
"struct_relogio" com o tempo de jogo.

Objetivo: Salvar em um arquivo "txt" de nome "tabuleiro{timestamp}.txt" as últimas informações do jogo. Escreve, no arquivo, o tempo de execução
de jogo até aquele momento, a pontuação do jogadores 1 e 2, o número de acerto dos jogadores 1 e 2, o número 1 ou 2, indicando o número de jogadores,
e as matrizes 17x17 ("tabuleiro_baixo", referente ao "back-end"). Os elementos dessas matrizes, que no início estavam zerados, ao longo do jogo 
foram sendo substituídos por números de acordo com a peça atingida. Então, quando o usuário quer gravar o jogo, essa configuração final da matriz 
é salva no arquivo.

Retorno: Não há retorno.
*/

_CRTIMP __cdecl __MINGW_NOTHROW struct_relogio carregar_jogo (int** , int** , int* , int* , int* , int* , int* );

/*
Cabeçalho: struct_relogio carregar_jogo (int** , int** , int* , int* , int* , int* , int* )

Argumentos: Matriz 17x17 do jogador 1 e 2, referente aos tabuleiros "back end", ponteiro para a variável com pontuação dos jogadores 1 e 2,  
variável com o número de acertos do jogador 1 e 2 e 

Objetivo: Abrir o arquivo salvo com o comando "GRAVAR" anteriormente para leitura. Ler as informações gravadas: o tempo de execução, a pontuação do jogador 1 e 2 e as matrizes 17x17 ("tabuleiro_baixo", referente ao "back-end").

Retorno: Retorna a struct "struct_relogio" com o tempo de exucução de onde o jogo deve continuar.
*/

_CRTIMP __cdecl __MINGW_NOTHROW void redesign_tabuleiro_alto (int** , char** , int );

/**/

_CRTIMP __cdecl __MINGW_NOTHROW void resetar_jogo (int** , int** , char** , char** , int* , int* , int* , int* );

/**/

#endif
