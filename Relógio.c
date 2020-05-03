#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

//PROTÓTIPOS
void relogio ();

//MAIN FUNCTION
int main (){

    relogio ();

    return 0;

} 

//AUX FUNCIONS

void relogio (){

    int horas = 0; int minutos = 0; int segundos = 0;

    while (1) {

		Sleep (1000);
		segundos++;
		system("cls");

	    if (segundos > 59) {
		    minutos++;
		    segundos = 0;
	    }
	    else if (minutos > 59) {
			horas++;
			minutos = 0;
	    }
	    else if (horas > 23) {
		    horas = 0;
	    }

		printf("%02d: %02d: %02d", horas, minutos, segundos);

	}

}
