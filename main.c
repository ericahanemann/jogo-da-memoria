#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>

void matriz();
void matrizjogo();
void jogo();
int compare();
void loop();

void main()
{
    char matriz1[6][6] = {{'A', 'A', 'B', 'B', 'C', 'C'},
                          {'D', 'D', 'E', 'E', 'F', 'F'},
                          {'G', 'G', 'H', 'H', 'I', 'I'},
                          {'J', 'J', 'K', 'K', 'L', 'L'},
                          {'M', 'M', 'N', 'N', 'O', 'O'},
                          {'P', 'P', 'Q', 'Q', 'R', 'R'}};

    char matriz2[6][6] = {{'?', '?', '?', '?', '?', '?'},
                          {'?', '?', '?', '?', '?', '?'},
                          {'?', '?', '?', '?', '?', '?'},
                          {'?', '?', '?', '?', '?', '?'},
                          {'?', '?', '?', '?', '?', '?'},
                          {'?', '?', '?', '?', '?', '?'}};
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

    if(op < 1 || op > 3){

            system("cls");
            printf("\nVocê digitou uma opção inválida, por favor digite a opção desejada: \n");
            main();

    }

    switch (op)
    {
    case 1:
        matriz(6, matriz1);
        for(int x = 10; x > 0; x--){
            printmatriz(6, matriz1);
            puts("");
            printf("você tem %d segundos para memorizar os cartões!\n", x);
            sleep(1);
            system("cls");

        }
        matrizjogo(6,matriz2 );
        loop(matriz1,matriz2);

        break;

        case 2:

        case 3:
            printf("Até logo!\n");
    }
}

void matriz(int t, char matriz1[t][t]){
    int i, lo, co, ld, cd;
    char temp;

    srand(time(NULL));
    for(i = 0; i <= 100000; i++){
        lo = rand() %6; //lo = linha origem
        co = rand() %6; //co = coluna origem
        ld = rand() %6; //ld = linha destino
        cd = rand() %6; //cd = coluna destino
        temp = matriz1[lo][co];
        matriz1[lo][co] = matriz1[ld][cd];
        matriz1[ld][cd] = temp;
    }
}

void printmatriz(int t, char matriz1[t][t]){
    int linha, coluna, i = 0;
    puts("     0     1     2     3     4     5 ");
    for(linha = 0; linha < t; linha++){

        puts("   |---|-|---|-|---|-|---|-|---|-|---|");
        for(coluna = 0; coluna < t; coluna++){
            if(coluna == 0){
                printf(" %d ", i);
                i++;}
            printf("| %c | ", matriz1[linha][coluna]);
            

        }

        puts("");

    }
    puts("   -----------------------------------\n ");
    printf("*************************************************\n"); i = 0;


}

void matrizjogo(int t, char matriz2[t][t], char matriz1[t][t]){
    int linha = 0, coluna=0, i = 0;

    puts("     0     1     2     3     4     5 ");

        for(linha = 0; linha < t; linha++){

            puts("   |---|-|---|-|---|-|---|-|---|-|---| ");
            for(coluna = 0; coluna < t; coluna++){
                if(coluna == 0){
                    printf(" %d ", i);
                    i++;}
                printf("| %c | ", matriz2[linha][coluna]);
            }

            puts("");

        }
    puts("   ----------------------------------- ");



}

void loop(char matriz1[6][6],char matriz2[6][6]){
        int a, b, i, j;

        puts("");
        puts("Insira a linha e a coluna da primeira peça: ");
        scanf("%d", &a );
        scanf("%d", &b);
        puts("Insira a linha e a coluna da segunda peça: ");
        scanf("%d", &i);
        scanf("%d", &j);
        compare(a, b, i, j, matriz1, matriz2);
}

int compare(int a, int b, int i, int j, char matriz1[6][6], char matriz2[6][6]){
    int op;
    char temp1 = 0, temp2 = 0;
    system("cls");

    temp1 = matriz2[a][b];
    temp2 = matriz2[i][j];

    matriz2[a][b] = matriz1[a][b];
    matriz2[i][j] = matriz1[i][j];
    matrizjogo(6,matriz2,matriz1);

    if(matriz1[a][b] == matriz1[i][j]){
        puts("");
        puts("ACERTOU!");
        sleep(5);
        system("cls");
        matrizjogo(6, matriz2, matriz1);
        loop(matriz1, matriz2);
    }
    
    else{
        puts("");
        puts("ERROU!");
        matriz2[a][b] = temp1;
        matriz2[i][j] = temp2;
        sleep(5);
        system("cls");
        matrizjogo(6,matriz2,matriz1);
        loop(matriz1,matriz2);
    }

return 0;
}
