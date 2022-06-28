#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int op;

    printf("----------------------------------------------\n");
    printf("              JOGO DA MEMÓRIA\n");
    printf("----------------------------------------------\n");
    printf("\n[1] Jogar\n");
    printf("[2] Como jogar\n");
    printf("[3] Sair\n");

    printf("\nDigite a opção desejada: ");
    scanf("%d", &op);
    system("cls");
    
    do {
         printf("----------------------------------------------\n");
        printf("              JOGO DA MEMÓRIA\n");
        printf("----------------------------------------------\n");
        printf("\n[1] Jogar\n");
        printf("[2] Como jogar\n");
        printf("[3] Sair\n");

        printf("\nVocê digitou uma opção inválida, por favor digite a opção desejada: ");
        scanf("%d", &op);
        system("cls");
    } while(op < 1 || op > 3);

    switch (op)
    {
    case 1:
        
        break;
    
    default:
        break;
    }
    return 0;
}



