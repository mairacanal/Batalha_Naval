# Projeto-Final---Batalha-Naval

Projeto Final da disciplina de Introdução à Programação para Engenharias (SSC0304)

Desenvolvimento de um jogo multiplayer baseado no clássico jogo "Batalha Naval" em linguagem C.

### Pré-requisitos

- *Sistema operacional:* Neste projeto foi utilizado o sistema operacional Windows

- *IDE:* O IDE utilizado foi o VScode (Visual Studio Code), o qual pode ser baixado pelo link: 
https://code.visualstudio.com/download
Para fazer o download, basta clicar na opção "Windows".
Além disso, é necessário instalar duas extensões no IDE após baixá-lo, disponíveis nesse tutorial: https://www.youtube.com/watch?v=aXVzbzwZuYc 

- *Compilador:* O compilador utilizado foi o MinGW, que pode ser instalado através desse tutorial: https://www.youtube.com/watch?v=FzPBZjkoEmA

### Funcionamento

Para o correto funcionamento do jogo é necessário que o usuário crie um diretório (uma pasta) no seu IDE para colocar os três arquivos existentes neste repositório: 
- Batalha_Naval.c --- que é o arquivo principal que contém o código do jogo
- Lib_Naval.h --- que é o arquivo header para a criação de uma biblioteca 
- Lib_Naval.c --- que é o arquivo .c para o desenvolvimento e adição das funções auxilares na biblioteca criada

Após a clonagem do código de cada arquivo para sua IDE, o jogo já está pronto para ser executado, basta entrar no código principal e clicar F6.

### Documentação 

#### Funções auxiliares:

- ```void regas()```     
Argumentos: não há argumentos  
Objetivo: Imprimir na tela do usuário as regras  
Retorno: não há retorno  

- ```void printar_menu()```     
Argumentos: não há argumentos    
Objetivo: Imprimir na tela do usuário o menu    
Retorno: não há retorno   

- ```int** alocar_tabuleiro_baixo()```    
Argumentos: não há argumentos    
Objetivo: Fazer a alocação de memória heap para uma matriz 17x17 e atribuir 0 a todos os bytes alocados (função calloc), a essa matriz foi dado o nome de tabuleiro_baixo  
Retorno: retorna o tabuleiro_baixo

- ```void free_tabuleiros(int** tabuleiro_baixo1, int** tabuleiro_baixo2, char **tabuleiro_alto1, char **tabuleiro_alto2)```    
Argumentos: EU PAREI AQUIIIIIIIIIIIIIII  
Objetivo: Fazer a alocação de memória heap para uma matriz 17x17 e atribuir 0 a todos os bytes alocados, a essa matriz foi dado o nome de tabuleiro_baixo  
Retorno: retorna o tabuleiro_baixo

- ```char** design_tabuleiro_alto()```  
Argumentos:   
Objetivo:    
Retorno:   

- ```void zerar_tabuleiros_baixos (int** tabuleiro_baixo1, int** tabuleiro_baixo2)```    
Argumentos:     
Objetivo:      
Retorno:     

 - ```jogada pow()```    
Argumentos:     
Objetivo:    
Retorno:   

- ```struct_relogio relogio(clock_t clock_inicial, struct_relogio addition)```
Argumentos:   
Objetivo:    
Retorno:   

 - ```void printar_jogador1(char** tabuleiro_alto2, int* pontuacao_j1, clock_t clock_inicial, struct_relogio addition)```  
Argumentos:   
Objetivo:    
Retorno:   

- ```void printar_jogador2(char** tabuleiro_alto1, int* pontuacao_j2, clock_t clock_inicial, struct_relogio addition);```
Argumentos: 
Objetivo:  
Retorno: 

- ```void func_jogador1(int** tabuleiro_baixo2, char** tabuleiro_alto2, int* pontuacao_j1, int* j1)```
Argumentos: 
Objetivo:  
Retorno: 

- ```void func_jogador2(int** tabuleiro_baixo1, char** tabuleiro_alto1, int* pontuacao_j2, int* j2)```
Argumentos: 
Objetivo:  
Retorno: 

- ```void gravar_jogo (int** tabuleiro_baixo1, int** tabuleiro_baixo2,  char **tabuleiro_alto1, char **tabuleiro_alto2, int pontuacao_j1, int pontuacao_j2, int j1, int j2, struct_relogio tempo_jogo)```
Argumentos: 
Objetivo:  
Retorno: 

- ```struct_relogio carregar_jogo (int** tabuleiro_baixo1, int** tabuleiro_baixo2,  char **tabuleiro_alto1, char **tabuleiro_alto2, int* pontuacao_j1, int* pontuacao_j2, int* j1, int* j2)```
Argumentos: 
Objetivo:  
Retorno: 

#### Bibliotecas criadas:

- ```constants.h```  
Arquivo header que contém todas as MACROS criadas para o jogo

- ```lib_naval.h```  
Arquivo header para criar a biblioteca que contém as funções auxiliares públicas, que são utilizadas no código principal: 
  
```void posicionar_armada (int** tabuleiro_baixo1, int** tabuleiro_baixo2)```  
Argumentos: o primeiro argumento deve consistir em uma matriz 17x17, referente ao tabuleiro "back-end" do jogador
1 e o segundo argumento deve consistir em uma matriz 17x17, referente ao tabuleiro "back-end" do jogador 2.  
Objetivo: Posicionar a armada do jogador 1 e do jogador 2 de forma aleatória, seguindo os designs de embarcação
disponibilizados em: https://docs.google.com/spreadsheets/d/1WBbv69VxdggPeCLtptqalj6iOX6eftSXgL8V4Xe4kGc/edit?usp=sharing
(acesso permitido para o domínio Universidade de São Paulo). Nesse arquivo em Excel, é possível ver, em rosa, 
o centro da embarcação, elemento essencial para a construção das embarcações.    
Retorno:
  
```void printar_tabuleiro (char **tabuleiro_alto)```  
Argumentos: recebe como argumento o tabuleiro "front-end" do jogado.   
Objetivo: imprime o tabuleiro "front-end" do jogador no terminal.  
Retorno: 

- ```lib_naval.c```  
Arquivo .c que contém o desenvolvimentos das funções públicas e a declaração e o desenvolvimento de funções privadas, as quais só são utilizadas para gerar a função "void posicionar armada":

```void portaavioes (int** tabuleiro_baixo)```    
Argumentos: recebe como argumento o tabuleiro "back-end" do jogado.   
Objetivo: Posicionar o porta-aviões no tabuleiro do jogador. No tabuleiro "back-end", o porta-aviões é representado
pelo número 2 ("dois"). A função rand() gera um centro (representado pelo bloco rosa no documento Excel) aleatório 
para o porta-aviões, de forma a possibilitar o posicionamento da embarcação.  
Retorno:  

```void couracados (int** tabuleiro_baixo)```  
Argumentos: recebe como argumento o tabuleiro "back-end" do jogador.    
Objetivo: Posicionar o couraçado no tabuleiro do jogador. No tabuleiro "back-end", o couraçado é representado
pelo número 3 ("três"). A função rand() gera um centro (representado pelo bloco rosa no documento Excel) aleatório 
para o couraçado, de forma a possibilitar o posicionamento da embarcaçã.   
Retorno:  

```void torpedeiros (int** tabuleiro_baixo)```
Argumentos: recebe como argumento o tabuleiro "back-end" do jogador.  
Objetivo: Posicionar o torpedeiro no tabuleiro do jogador. No tabuleiro "back-end", o torpedeiro é representado
pelo número 4 ("quatro"). A função rand() gera um centro (representado pelo bloco rosa no documento Excel) aleatório 
para o torpedeiro, de forma a possibilitar o posicionamento da embarcação.  

```void hidroavioes (int** tabuleiro_baixo)```
Argumentos: recebe como argumento o tabuleiro "back-end" do jogador.  
Objetivo: Posicionar o hidroavião no tabuleiro do jogador. No tabuleiro "back-end", o hidroavião é representado
pelo número  ("cinco"). A função rand() gera um centro (representado pelo bloco rosa no documento Excel) aleatório 
para o hidroavião, de forma a possibilitar o posicionamento da embarcação.  
Retorno:  

### Autores

Maíra Canal - @mairacanal  
Caroline Grupe - @Carolgrupe









