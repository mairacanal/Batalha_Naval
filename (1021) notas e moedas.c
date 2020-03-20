#include <stdio.h>
#include <math.h>


int main (void){
    short int valor;
    short int n100, n50, n20, n10, n5, n2, n1;
    printf("-------------- SAQUE -------------- \nValor: R$");
    scanf("%d", &valor);
    if (valor>=100){
        n100 = valor/100;
        valor = valor % 100;
    }
    if (20 < valor < 100 && valor != 0){
        n50 = valor/50;
        valor = valor % 50;
    }
    if (10 < valor < 50 && valor != 0){
        n20 = valor/20;
        valor = valor % 20;
    }
    if (5 < valor < 20  && valor != 0){
        n10 = valor/10;
        valor = valor % 10;
    }
    if (2 < valor < 10 && valor != 0){
        n5 = valor/5;
        valor = valor % 5;
    }
    if (1 < valor < 5  && valor != 0){
        n2 = valor/2;
        valor = valor % 2;
    }
    if (valor == 1){
        n1 = valor;
    }
    printf("NOTAS\n");
    if (n100 != 0){
        printf("%d notas de R$100,00\n", n100);
    }
    if (n50 != 0){
        printf("%d notas de R$50,00\n", n50);
    }
    if (n20 != 0){
        printf("%d notas de R$20,00\n", n20);
    }
    if (n10 != 0){
        printf("%d notas de R$10,00\n", n10);
    }
    if (n5 != 0){
        printf("%d notas de R$5,00\n", n5);
    }
    if (n2 != 0){
        printf("%d notas de R$2,00\n", n2);
    }
    if (n1 != 0){
        printf("%d notas de R$1,00\n", n1);
    }
    return 0;
}