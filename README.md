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

- ```void regras()```     
  
Argumentos: Não há argumentos.  
  
Objetivo: Imprimir, na tela do usuário, as regras.  
  
Retorno: Não há retorno.  

- ```void printar_menu()```  

Argumentos: Não há argumentos.   

Objetivo: Imprimir, na tela do usuário, o menu.    

Retorno: Não há retorno.   

- ```int** alocar_tabuleiro_baixo()```   

Argumentos: não há argumentos.    

Objetivo: Fazer a alocação de memória heap para uma matriz 17x17 e atribuir 0 a todos os bytes alocados (função calloc), a essa matriz foi dado o nome de tabuleiro_baixo (referente ao tabuleiro "back-end").  

Retorno: Uma matriz 17x17, referente ao tabuleiro_baixo de um dos jogadores.    

- ```void free_tabuleiros(int** , int** , char **, char **)```      

Argumentos: As duas matrizes 17x17 criadas e alocadas,"tabuleiro_baixo" e os dois vetores de string criados e alocados, "tabuleiro_alto".    

Objetivo: Desalocar a memória de cada uma dessas matrizes.    

Retorno: Não há retorno. 

- ```void lateral_tabuleiro_alto (char**)```  

Argumentos: Vetor de strings chamado de tabuleiro_alto (referente ao tabuleiro "front-end").  

Objetivo: Definir as strings em cada elemento do vetor determinadas pela primeira linha (que contém as letras de A a P) e pela primeira coluna (que contém os números de 1 a 16) do tabuleiro de cada jogador da batalha naval.    

Retorno: Não há retorno.  
  
- ```void desenho_tabuleiro_alto (char** )```  

Argumentos: Vetor de strings, referente ao tabuleiro_alto do jogador (tabuleiro "front-end").  

Objetivo: Preenche o vetor interior de strings com a seguinte string: "    |"  

Retorno: Não há retorno.  

 - ```char** design_tabuleiro_alto ()```     
Argumentos: Não há argumentos.  

Objetivo: Alocar memória para um vetor de strings com 289 strings (17x17), referente ao "tabuleiro_alto", e preenchê-lo com o design 
escolhido para o tabuleiro, utilizando as funções desenho_tabuleiro_alto (char** ) e design_tabuleiro_alto ().        

Retorno: Retorna o tabuleiro_alto.  

- ```void zerar_tabuleiros_baixos (int** , int**)```        

Argumentos: As duas matrizes 17x17 do jogador 1 e 2.    

Objetivo: Colocar 0 em todos os espaços alocados para essas matrizes.     

Retorno: Não há retorno.           

 - ```jogada pow()```      
 
Argumentos: Não há argumentos.     

Objetivo: Recebe as coordenadas digitadas pelo usuário para transformá-las em coordenadas númericas que possam ser utilizadas para a 
identificar essa posição no tabuleiro baixo.  

Retorno: Struct "jogada", que contem os valores da linha e da coluna que o usuário escolheu para atingir.   

- ```struct_relogio relogio(clock_t, struct_relogio )```  

Argumentos: long "clock_t" que contem o clock do momento em que o jogador iniciou o jogo e uma struct "struct_relogio" que adiciona o tempo de execução de jogo, em casos de jogos carregados.  

Objetivo: Utilizar a struct "relogio" para guardar os valores dos segundos, minutos e horas no momento em que a função é chamada. 

Retorno: Struct "struct_relogio" com o valor de segundos, minutos e horas.     

 - ```void printar_jogador1(char**, int*, clock_t, struct_relogio)```    
 
Argumentos: Vetor de strings do jogador 2 ("tabuleiro_alto2"), pontuação do jogador 1, long "clock_t" que armazena o tempo inicial de jogo  e a struct "struct_relogio" que adiciona o tempo prévio de execução, em caso de jogos carregados.  

Objetivo: Essa função imprime a tela do jogador 1, de forma a imprimir o tabuleiro "front end" do jogador 2, por meio da função printar_tabuleiro(), a pontuação do jogador 1 e o tempo de jogo nesse momento.   
Retorno: Não há retorno.  

- ```void printar_jogador2(char**, int*, clock_t, struct_relogio)```  

Argumentos: Vetor de strings do jogador 1 ("tabuleiro_alto1"), pontuação do jogador 2, long "clock_t" que armazena o tempo inicial de jogo  e a struct "struct_relogio" que adiciona o tempo prévio de execução, em caso de jogos carregados.  

Objetivo: Essa função imprime a tela do jogador 2, de forma a imprimir o tabuleiro "front end" do jogador 1, por meio da função printar_tabuleiro(), a pontuação do jogador 2 e o tempo de jogo nesse momento.  

Retorno: Não há retorno.

- ```bool func_jogador1(int**, char**, int*  int*)```  

Argumentos: Matriz 17x17 do jogador 2, referente ao tabuleiro "back-end", vetor de strings do jogador 2, referente ao tabueleiro "front-end", ponteiro para a variável de pontuação do jogador 1 e ponteiro para a variável que armazena o número de acertos do jogador 1.  

Objetivo: Calcular a pontuação do jogador 1. A pontuação do jogador 1 varia a cada jogada. Ela recebe um valor específico dependendo da peça que o jogador atingiu e perde um certo valor quando ele atinge a água. As MACROS que definem esses valores estão declaradas na biblioteca "constants.h". O valor de "j1" aumenta em 1 cada vez que o jogador acerta o ataque em alguma peça.  

Retorno: Retorna uma variável booleana, sendo essa "true" se o valor da variável "j1" do jogador 1 chegar a 84 e "false" se não. Essa variável ponta se o jogador ganhou o jogo, isto é, acertou todas as posições de todas as embarcações.  

- ```bool func_jogador2(int** tabuleiro_baixo1, char** tabuleiro_alto1, int* pontuacao_j2, int* j2)```  

Argumentos: Matriz 17x17 do jogador 1, referente ao tabuleiro "back-end", vetor de strings do jogador 1, referente ao tabueleiro "front-end", ponteiro para a variável de pontuação do jogador 1, ponteiro para a variável que armazena o número de acertos do jogador 1 e uma variável booleana que aponta se o jogo está no modo single ou multiplayer.  

Objetivo: Caso a variável booleana seja "false", indica que o jogo está no modo "JOGADOR X COMPUTADOR". Nesse modo, essa função gera dois números aleatórios entre 1 e 16, referentes a linha e a coluna da jogada. Caso a variável booleana seja "true", indica que o jogo está no modo "JOGADOR X JOGADOR". Nesse modo, essa função recebe as coordenadas númeras do disparo do jogador e realiza a correspondência entre o tabuleiro alto e o tabuleiro baixo. Além disso, calcular a pontuação do jogador 2, a qual varia a cada jogada. Ela recebe um valor específico dependendo da peça que o jogador atingiu e perde um certo valor quando ele atinge a água. As MACROS que definem esses valores estão declaradas na biblioteca "constants.h". O valor de "j2" aumenta em 1 cada vez que o jogador acerta o ataque em alguma peça.   

Retorno: Ua variável booleana, sendo essa "true" se o valor da variável "j2" do jogador 2 chegar a 84 e "false" se não. Essa variável aponta se o jogador ganhou o jogo, isto é, acertou todas as posições de todas as embarcações.

- ```void gravar_jogo (int** tabuleiro_baixo1, int** tabuleiro_baixo2,  char **tabuleiro_alto1, char **tabuleiro_alto2, int pontuacao_j1, int pontuacao_j2, int j1, int j2, struct_relogio tempo_jogo)```  
Argumentos: Matriz 17x17 do jogador 1 e 2, vetor de strings do jogador 1 e 2, pontuação por ataque do jogador 1 e 2, variável para iteração a cada acerto do jogador 1 e 2 e a struct "struct_relogio" gerada na última jogada.   
Objetivo: Salvar em um arquivo de escrita, com o nome que o usuário digitar, as últimas informações do jogo. Salva o tempo de exucução de jogo até aquele momento, a pontuação do jogador 1 e 2 e as matrizes 17x17 ("tabuleiro_baixo", referente ao "back-end"). Os elementos dessas matrizes, que no início estavam zerados, ao longo do jogo foram sendo substituídos por números de acordo com a peça atingida. Então, quando o usuário quer gravar o jogo, essa configuração final da matriz é salva no arquivo.  
Retorno: Não há retorno.    

- ```struct_relogio carregar_jogo (int** tabuleiro_baixo1, int** tabuleiro_baixo2, int* pontuacao_j1, int* pontuacao_j2, int* j1, int* j2)```  
Argumentos: Matriz 17x17 do jogador 1 e 2, pontuação por ataque do jogador 1 e 2 e variável para iteração a cada acerto do jogador 1 e 2.  
Objetivo: Abrir o arquivo salvo com o comando "GRAVAR" anteriormente para leitura. Ler as informações gravadas: o tempo de execução, a pontuação do jogador 1 e 2 e as matrizes 17x17 ("tabuleiro_baixo", referente ao "back-end").    
Retorno: Retorna a struct "struct_relogio" com o tempo de exucução de onde o jogo deve continuar.   

- ```void redesign_tabuleiro_alto (int** tabuleiro_baixo, char** tabuleiro_alto, int n)```  
Argumentos: Matriz 17x17 (beack-end), vetor de strings (front-end) e uma variável para identificar qual o referente jogador.  
Objetivo: A partir do "tabuleiro_baixo" que foi salvo no arquivo e, posteriormente, lido, o "tabuleiro_alto" é reconstruído, subbstituindo os números referentes a água ou a alguma peça pelos seus símbolos e reformulando o design.  
Retorno: Não há retorno.     

- ```void resetar_jogo (int** tabuleiro_baixo1, int** tabuleiro_baixo2, char** tabuleiro_alto1, char** tabuleiro_alto2, int* pontuacao_j1, int* pontuacao_j2, int* j1, int* j2)```  
Argumentos: Matriz 17x17 do jogador 1 e 2, vetor de strings do jogador 1 e 2, pontuação por ataque do jogador 1 e 2, variável para iteração a cada acerto do jogador 1 e 2.  
Objetivo: Zerar todos os elementos das matrizes ("tabuleiro_baixo"), refazer os vetores de strings ("tabuleiro_alto") somente com o design e zerar a pontuação por ataque dos dois jogadores e as duas variáveis de iteração, assim permitindo que o jogo seja reiniciado.   
Retorno: Não há retorno.  

#### Bibliotecas criadas:

- ```constants.h```    
Arquivo header que contém todas as MACROS criadas para o jogo.  

- ```lib_naval.h```    
Arquivo header para criar a biblioteca que contém as funções auxiliares públicas, que são utilizadas no código principal:   
  
```void posicionar_armada (int** tabuleiro_baixo1, int** tabuleiro_baixo2)```    
Argumentos: o primeiro argumento deve consistir em uma matriz 17x17, referente ao tabuleiro "back-end" do jogador 1 e o segundo argumento deve consistir em uma matriz 17x17, referente ao tabuleiro "back-end" do jogador 2.    
Objetivo: Posicionar a armada do jogador 1 e do jogador 2 de forma aleatória, seguindo os designs de embarcação disponibilizados em: https://docs.google.com/spreadsheets/d/1WBbv69VxdggPeCLtptqalj6iOX6eftSXgL8V4Xe4kGc/edit?usp=sharing (acesso permitido para o domínio Universidade de São Paulo). Nesse arquivo em Excel, é possível ver, em rosa, o centro da embarcação, elemento essencial para a construção das embarcações.        
Retorno: Não há retorno.    
  
```void printar_tabuleiro (char **tabuleiro_alto)```    
Argumentos: recebe como argumento o tabuleiro "front-end" do jogado.     
Objetivo: imprime o tabuleiro "front-end" do jogador no terminal.    
Retorno: Não há retorno.   

- ```lib_naval.c```    
Arquivo .c que contém o desenvolvimentos das funções públicas e a declaração e o desenvolvimento de funções privadas, as quais só são utilizadas para gerar a função "void posicionar armada":  

```void portaavioes (int** tabuleiro_baixo)```      
Argumentos: recebe como argumento o tabuleiro "back-end" do jogado.     
Objetivo: Posicionar o porta-aviões no tabuleiro do jogador. No tabuleiro "back-end", o porta-aviões é representado pelo número 2 ("dois"). A função rand() gera um centro (representado pelo bloco rosa no documento Excel) aleatório para o porta-aviões, de forma a possibilitar o posicionamento da embarcação.    
Retorno: Não há retorno.   

```void couracados (int** tabuleiro_baixo)```  
Argumentos: recebe como argumento o tabuleiro "back-end" do jogador.    
Objetivo: Posicionar o couraçado no tabuleiro do jogador. No tabuleiro "back-end", o couraçado é representado pelo número 3 ("três"). A função rand() gera um centro (representado pelo bloco rosa no documento Excel) aleatório para o couraçado, de forma a possibilitar o posicionamento da embarcaçã.     
Retorno: Não há retorno.   

```void torpedeiros (int** tabuleiro_baixo)```    
Argumentos: recebe como argumento o tabuleiro "back-end" do jogador.    
Objetivo: Posicionar o torpedeiro no tabuleiro do jogador. No tabuleiro "back-end", o torpedeiro é representado pelo número 4 ("quatro"). A função rand() gera um centro (representado pelo bloco rosa no documento Excel) aleatório para o torpedeiro, de forma a possibilitar o posicionamento da embarcação.  
Retorno: Não há retorno.    

```void hidroavioes (int** tabuleiro_baixo)```  
Argumentos: recebe como argumento o tabuleiro "back-end" do jogador.    
Objetivo: Posicionar o hidroavião no tabuleiro do jogador. No tabuleiro "back-end", o hidroavião é representado pelo número  ("cinco"). A função rand() gera um centro (representado pelo bloco rosa no documento Excel) aleatório para o hidroavião, de forma a possibilitar o posicionamento da embarcação.      
Retorno: Não há retorno.     

### Autores

Maíra Canal - @mairacanal  
Caroline Grupe - @Carolgrupe









