#define LINHAS 17                     // Número de linhas do tabuleiro "back-end"
#define COLUNAS 17                    // Número de colunas do tabuleiro "back-end"
#define STRINGS 289                   // Número de strings do vetor que forma o tabuleiro "front-end" 
#define NUM_CHAR 7                    // Número máximo de caracteres de cada uma das strings do vetor

#define PONTUA_P 43                   // Pontuação recebida quando o usuário atinge um elemento do Porta-aviões
#define PONTUA_C 78                   // Pontuação recebida quando o usuário atinge um elemento do Couraçado
#define PONTUA_T 82                   // Pontuação recebida quando o usuário atinge um elemento do Torpedeiro
#define PONTUA_H 125                  // Pontuação recebida quando o usuário atinge um elemento do Hidro-avião
#define PONTUA_ERRO -3                // Pontuação perdida quando o usuário atinge a água

#define NUM_COURACADOS 2              // Número de couraçados (2)
#define NUM_TORPEDEIROS 3             // Número de torpedeiros (3)
#define NUM_HIDROAVIOES 4             // Número de hidroaviões (4)

/* Fórmula para definir os valores da pontuação e do erro:

    Pontuação: ((N_blocos_peça * N_peças)* 1000)/N_posições_tabuleiro

Onde: 
N_blocos_peça: número total de blocos que a peça que foi atingida ocupa.
N_peças: quantidade de peças disponíveis no jogo, para aquela que foi atingida.
N_posições_tabuleiro: Número total de posições no tabuleiro (256).

    Erro: ((N_posições_tabuleiro - N_blocos_total_peças)/N_posições_tabuleiro)*5

Onde:
N_posições_tabuleiro: Número total de posições no tabuleiro (256).
N_blocos_total_peças: Indica a quantidade de blocos total que as peças da armada ocupam (84).
*/