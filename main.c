#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define TAM 36

void shuffle();

void main(){
    printf("**************************************************************************************************************************************\n");
    printf("\n");
    printf ("\t\t\t\tBEM VINDO AO JOGO\n");
    printf("\n");
    printf("**************************************************************************************************************************************\n");

    int op;

    printf("\n");
    printf("**************************************************************************************************************************************\n");
    printf("\n");
    printf("\t\t\t\tSelecione a opção que preferir\n");
    printf("\n");
    printf("\t\t\t\t1 - Jogar\n");
    printf("\t\t\t\t0 - Sair\n");
    printf("\n");
    printf("**************************************************************************************************************************************\n");

    scanf("%d", &op);

    switch(op){
        case 1:{
            shuffle();
            break;
        }
        case 0:{
            puts("Até logo!!");
            break;
        }
    }


}

void shuffle(){
    int i, c,a,b, r;
    char cards[6][6];
    c = 0;
    a = 0;
    b = 0;
    while(c < TAM){
        r = rand() % 18;
        cards[a][b] = r;
        printf("cards[%d][%d] =\t %i\n", a, b, cards[a][b]);
        if(b < 6){
            b++;

        }
        else if (b == 6) {
               b = 1;
                a++;
            }


        c++;

    }
}
