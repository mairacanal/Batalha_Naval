#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// OBS.: Falta o "Dumb Proof": se linha > 16 ou coluna > 16
typedef struct {
    int linha;
    int coluna;
} jogada;

jogada pow (){
    char comando[8];
    jogada coordenadas;
    scanf("%s", comando);
    if (comando[0] == 'P' && comando[1] == 'O' && comando[2] == 'W'){
        char coordenadas_ins[4], letra;
        scanf("%s", coordenadas_ins);
        coordenadas.linha = atoi(coordenadas_ins);
        letra = coordenadas_ins [strlen(coordenadas_ins) - 1]; 
        switch (letra) {
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
        }
    }
    else {
        printf("ERRO! Comando invalido.");
    }
    return (coordenadas);
}

int main (){
    jogada coordenada = pow ();
    printf("%d %d", coordenada.linha, coordenada.coluna);
    
    /*char comando[8];
    scanf("%s", comando);
    if (comando[0] == 'P' && comando[1] == 'O' && comando[2] == 'W'){
        char coordenadas_ins[4], letra;
        posicao coord;
        scanf("%s", coordenadas_ins);
        coord.linha = atoi(coordenadas_ins);
        letra = coordenadas_ins [strlen(coordenadas_ins) - 1]; 
        switch (letra) {
            case 'A':
                coord.coluna = 1;
                break;
            case 'B':
                coord.coluna = 2;
                break;
            case 'C':
                coord.coluna = 3;
                break;
            case 'D':
                coord.coluna = 4;
                break;
            case 'E':
                coord.coluna = 5;
                break;
            case 'F':
                coord.coluna = 6;
                break;
            case 'G':
                coord.coluna = 7;
                break;
            case 'H':
                coord.coluna = 8;
                break;
            case 'I':
                coord.coluna = 9;
                break;
            case 'J':
                coord.coluna = 10;
                break;
            case 'K':
                coord.coluna = 11;
                break;
            case 'L':
                coord.coluna = 12;
                break;
            case 'M':
                coord.coluna = 13;
                break;
            case 'N':
                coord.coluna = 14;
                break;
            case 'O':
                coord.coluna = 15;
                break;
            case 'P':
                coord.coluna = 16;
                break;
            default:
                printf("ERRO! Essa posicao nao existe!");
        }
    }*/
    return 0;
} 