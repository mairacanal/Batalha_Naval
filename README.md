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

### Autores

Maíra Canal - @mairacanal  
Caroline Grupe - @Carolgrupe

