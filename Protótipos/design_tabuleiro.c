#include <stdio.h>
#include <stdlib.h>
#define STRINGS 289
#define NUM_CHAR 7

int main (){
    int c = 17;
    char **tabuleiro_alto = (char **) malloc (STRINGS * sizeof(char *));
    for(int i = 0; i < STRINGS; i++){
        tabuleiro_alto[i] = (char *) malloc (NUM_CHAR * sizeof(char));
    }

    tabuleiro_alto[0] = "|    |";
    tabuleiro_alto[1] = " A |";
    tabuleiro_alto[2] = " B |";
    tabuleiro_alto[3] = " C |";
    tabuleiro_alto[4] = " D |";
    tabuleiro_alto[5] = " E |";
    tabuleiro_alto[6] = " F |";
    tabuleiro_alto[7] = " G |";
    tabuleiro_alto[8] = " H |";
    tabuleiro_alto[9] = " I |";
    tabuleiro_alto[10] = " J |";
    tabuleiro_alto[11] = " K |";
    tabuleiro_alto[12] = " L |";
    tabuleiro_alto[13] = " M |";
    tabuleiro_alto[14] = " N |";
    tabuleiro_alto[15] = " O |";
    tabuleiro_alto[16] = " P |"; 
    tabuleiro_alto[17] = "| 1  |";
    tabuleiro_alto[34] = "| 2  |";
    tabuleiro_alto[51] = "| 3  |";
    tabuleiro_alto[68] = "| 4  |";
    tabuleiro_alto[85] = "| 5  |";
    tabuleiro_alto[102] = "| 6  |";
    tabuleiro_alto[119] = "| 7  |";
    tabuleiro_alto[136] = "| 8  |";        
    tabuleiro_alto[153] = "| 9  |";
    tabuleiro_alto[170] = "| 10 |";
    tabuleiro_alto[187] = "| 11 |";
    tabuleiro_alto[204] = "| 12 |";
    tabuleiro_alto[221] = "| 13 |";
    tabuleiro_alto[238] = "| 14 |";
    tabuleiro_alto[255] = "| 15 |";
    tabuleiro_alto[272] = "| 16 |";

    for (int i = 17; i < STRINGS; i++){
        if (c == 17) c = 0;
        else {
            tabuleiro_alto[i] = "   |";
        }
        c++;
    }
    c = 0;
    for(int i = 0; i < STRINGS; i++){
        c++;
        if (c == 17){
            c = 0;
            printf("%s\n", tabuleiro_alto[i]);
        }
        else {
            printf("%s", tabuleiro_alto[i]);
        }
    }
    return 0;
}