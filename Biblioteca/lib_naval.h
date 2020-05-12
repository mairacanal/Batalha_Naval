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

#endif