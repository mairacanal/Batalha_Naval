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

Para o correto funcionamento do jogo é necessário que o usuário crie um diretório (uma pasta) no seu IDE para colocar os quatro arquivos existentes neste repositório: 
- batalha_naval.c --- arquivo principal que contém o código do jogo
- lib_naval.h --- arquivo header para a criação de uma biblioteca e declaração das funções e structs
- lib_naval.c --- arquivo para o desenvolvimento das funções auxilares 
- constants.h --- arquivo header que contém todas as MACROS utilizadas 

Após a clonagem do código de cada arquivo para sua IDE, o jogo já está pronto para ser executado. Para isso, é necessário que o usuário ache e copie o caminho para o diretório que contém os arquivos acima, abra o "prompt de comando" e digite "cd (caminho para o diretório)" e aperte _enter_. Depois, digite "gcc batalha_naval.c constants.h lib_naval.c -o (nome do arquivo a sua escolha).exe" e clique _enter_. E, por último, digite "start (nome escolhido).exe".

### Documentação 

#### Funções auxiliares desenvolvidas na bilbioteca "lib_naval.c" e declaradas na biblioteca "lib_naval.h" (funções públicas):

```void posicionar_armada (int**, int**)```    

Argumentos: o primeiro argumento deve consistir em uma matriz 17x17, referente ao tabuleiro "back-end" do jogador 1 e o segundo argumento deve consistir em uma matriz 17x17, referente ao tabuleiro "back-end" do jogador 2.    

Objetivo: Posicionar a armada do jogador 1 e do jogador 2 de forma aleatória, seguindo os designs de embarcação disponibilizados em: https://docs.google.com/spreadsheets/d/1WBbv69VxdggPeCLtptqalj6iOX6eftSXgL8V4Xe4kGc/edit?usp=sharing (acesso permitido para o domínio Universidade de São Paulo). Nesse arquivo em Excel, é possível ver, em rosa, o centro da embarcação, elemento essencial para a construção das embarcações.        

Retorno: Não há retorno.    
  
```void printar_tabuleiro (char**)```    

Argumentos: recebe como argumento o tabuleiro "front-end" do jogado.     

Objetivo: imprime o tabuleiro "front-end" do jogador no terminal.    

Retorno: Não há retorno.   

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

- ```void lateral_tabuleiro_alto(char**)```  

Argumentos: Vetor de strings chamado de tabuleiro_alto (referente ao tabuleiro "front-end").  

Objetivo: Definir as strings em cada elemento do vetor determinadas pela primeira linha (que contém as letras de A a P) e pela primeira coluna (que contém os números de 1 a 16) do tabuleiro de cada jogador da batalha naval.    

Retorno: Não há retorno.  
  
- ```void desenho_tabuleiro_alto(char**)```  

Argumentos: Vetor de strings, referente ao tabuleiro_alto do jogador (tabuleiro "front-end").  

Objetivo: Preenche o vetor interior de strings com a seguinte string: "    |"  

Retorno: Não há retorno.  

 - ```char** design_tabuleiro_alto()```     
 
Argumentos: Não há argumentos.  

Objetivo: Alocar memória para um vetor de strings com 289 strings (17x17), referente ao "tabuleiro_alto", e preenchê-lo com o design 
escolhido para o tabuleiro, utilizando as funções desenho_tabuleiro_alto (char** ) e design_tabuleiro_alto ().        

Retorno: Retorna o tabuleiro_alto.  

- ```void zerar_tabuleiros_baixos(int** , int**)```        

Argumentos: As duas matrizes 17x17 do jogador 1 e 2.    

Objetivo: Colocar 0 em todos os espaços alocados para essas matrizes.     

Retorno: Não há retorno.           

 - ```jogada pow()```      
 
Argumentos: Não há argumentos.     

Objetivo: Recebe as coordenadas digitadas pelo usuário para transformá-las em coordenadas númericas que possam ser utilizadas para a 
identificar essa posição no tabuleiro baixo.  

Retorno: Struct "jogada", que contem os valores da linha e da coluna que o usuário escolheu para atingir.   

- ```struct_relogio relogio(clock_t, struct_relogio)```  

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

- ```bool func_jogador2(int**, char**, int*, int*)```  

Argumentos: Matriz 17x17 do jogador 1, referente ao tabuleiro "back-end", vetor de strings do jogador 1, referente ao tabueleiro "front-end", ponteiro para a variável de pontuação do jogador 1, ponteiro para a variável que armazena o número de acertos do jogador 1 e uma variável booleana que aponta se o jogo está no modo single ou multiplayer.  

Objetivo: Caso a variável booleana seja "false", indica que o jogo está no modo "JOGADOR X COMPUTADOR". Nesse modo, essa função gera dois números aleatórios entre 1 e 16, referentes a linha e a coluna da jogada. Caso a variável booleana seja "true", indica que o jogo está no modo "JOGADOR X JOGADOR". Nesse modo, essa função recebe as coordenadas númeras do disparo do jogador e realiza a correspondência entre o tabuleiro alto e o tabuleiro baixo. Além disso, calcular a pontuação do jogador 2, a qual varia a cada jogada. Ela recebe um valor específico dependendo da peça que o jogador atingiu e perde um certo valor quando ele atinge a água. As MACROS que definem esses valores estão declaradas na biblioteca "constants.h". O valor de "j2" aumenta em 1 cada vez que o jogador acerta o ataque em alguma peça.   

Retorno: Uma variável booleana, sendo essa "true" se o valor da variável "j2" do jogador 2 chegar a 84 e "false" se não. Essa variável aponta se o jogador ganhou o jogo, isto é, acertou todas as posições de todas as embarcações.

- ```void gravar_jogo (int**, int**, char**, char**, int, int, int, int, struct_relogio)```  

Argumentos: Matriz 17x17 do jogador 1 e 2, referente aos tabuleiros "back end" dos jogadores, variável com pontuação do jogador 1 e 2, variável com o número de acertos do jogador 1 e 2, uma variável booleana que aponta se o jogo está no modo multiplayer ou singleplayer e a struct "struct_relogio" com o tempo de jogo.  

Objetivo: Salvar em um arquivo "txt" de nome "tabuleiro{timestamp}.txt" as últimas informações do jogo. Escreve, no arquivo, o tempo de execução de jogo até aquele momento, a pontuação do jogadores 1 e 2, o número de acerto dos jogadores 1 e 2, o número 1 ou 2, indicando o número de jogadores, e as matrizes 17x17 ("tabuleiro_baixo", referente ao "back-end"). Os elementos dessas matrizes, que no início estavam zerados, ao longo do jogo foram sendo substituídos por números de acordo com a peça atingida. Então, quando o usuário quer gravar o jogo, essa configuração final da matriz é salva no arquivo.  

Retorno: Não há retorno.  

- ```struct_relogio carregar_jogo (int**, int**, int*, int*, int*, int*)```  


Argumentos: Matriz 17x17 do jogador 1 e 2, referente aos tabuleiros "back end", ponteiros para as variáveis com as pontuações dos jogadores 1 e 2, ponteiros para as variáveis com o número de acertos dos jogadores 1 e 2 e ponteiro para a variável com o número de jogadores.  

Objetivo: Abrir o arquivo salvo com o comando "GRAVAR" anteriormente para leitura. Ler as informações gravadas: o tempo de execução, a pontuação do jogadores 1 e 2, o número de acerto dos jogadores 1 e 2, o número de jogadores e as matrizes 17x17 ("tabuleiro_baixo", referente ao "back-end").  

Retorno: Struct "struct_relogio" com o tempo de execução de onde o jogo deve continuar.  

- ```void redesign_tabuleiro_alto (int**, char**, int)```  

Argumentos: Matriz 17x17, referente ao tabuleiro "back end", vetor de strings, referente ao tabuleiro "front end" e uma variável para identificar qual o referente jogador.  

Objetivo: A partir do tabuleiro "back end" que foi salvo no arquivo e, posteriormente, lido, o tabueleiro "front end" é reconstruído, substituindo os números referentes à água ou a alguma peça pelos seus símbolos, de forma a reformular o design.  

Retorno: Não há retorno.  

- ```void resetar_jogo (int**, int**, char**, char**, int*, int*, int*, int*)```  

Argumentos: Matrizes 17x17 dos jogadores 1 e 2, referente aos tabuleiros "back end", vetores de strings dos jogadores 1 e 2, referente aos tabuleiros "front end", ponteiros para a pontuações dos jogadores 1 e 2 e ponteiros para as variáveis com o número de acertos dos jogadores 1 e 2.  

Objetivo: Zerar todos os elementos das matrizes, referente ao tabuleiro "back end", refazer os vetores de strings, referente ao tabuleiro "front end", somente com o design inicial e zerar as pontuações dos dois jogadores e as duas variáveis com os números de acerto dos jogadores, assim permitindo que o jogo seja reiniciado.  

Retorno: Não há retorno.  

#### Funções auxiliares somente desenvolvidas na bilbioteca "lib_naval.c" (funções privadas):

Essas funções só são utilizadas para gerar a função "void posicionar armada":  
  
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









