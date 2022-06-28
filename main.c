#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void matriz();

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
        matriz();
        break;
    }
    return 0;
}

void matriz(){
    char vetor[36] = {"A", "A", "B", "B", "C", "C", "D", "D", "E", "E", "F", "F", "G", "G", "H", "H", "I", "I", "J", "J", "K", "K", "L", "L", "M", "M", "N", "N", "O", "O", "P", "P", "Q", "Q", "R", "R"}; 
    char matriz1[6][6] = {{0, 0, 0, 0, 0, 0},
                                                      {0, 0, 0, 0, 0, 0},
                                                      {0, 0, 0, 0, 0, 0},
                                                      {0, 0, 0, 0, 0, 0},
                                                      {0, 0, 0, 0, 0, 0},
                                                      {0, 0, 0, 0, 0, 0}};
    int linha1, coluna1, vetelemento;

        for(vetelemento = 0; vetelemento = 35; vetelemento++){
            do{
                linha1 = rand() %5;
                coluna1 = rand() %5;
            }while (matriz1[linha1][coluna1] != 0);

            matriz1[linha1][coluna1] = vetor[vetelemento];
        }

    printf("%d", matriz1);
}



