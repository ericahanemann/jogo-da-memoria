#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <locale.h> //foi utilizada para mudar idioma

void matriz();
void matrizjogo();
void jogo();
int compare();
void loop();

int main()
{
    setlocale(LC_ALL, "Portuguese"); //muda o idioma para português, corrigindo acentuações
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

    int op, op2, tentativas = 0;

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
            printf("você tem %d segundos para memorizar as peças!\n", x);
            sleep(1);
            system("cls");

        }
        matrizjogo(6,matriz2 );
        loop(tentativas, matriz1, matriz2);

            break;
        case 2:
            printf("Olá, bem vindo ao jogo da memória!\n");
            printf("\nOBJETIVO DO JOGO:");
            printf("\nEncontrar todos os pares de peças no tabuleiro 6x6.\n");
            printf("\nCOMO JOGAR:");
            printf("\nVocê terá apenas 10 segundos para memorizar as peças. Quando esse tempo se esgotar as peças seram viradas para baixo e você deve informar quais peças você acha que formam um par.");
            printf("\nSe as peças escolhidas forem iguais, elas continuarão sendo exibidas e você já pode tentar encontrar o próximo par.");
            printf("\nPorém, se as peças forem diferentes, elas seram viradas novamente e você deve fazer mais uma tentativa.\n");

            do{
                printf("\n[1] Voltar");
                printf("\n[2] Sair do jogo\n");
                printf("Digite a opção desejada: ");
                scanf("%d", &op2);
            } while(op2 < 1 && op2 > 2);

            switch (op2) {
                case 1:
                system("cls");
                    main();

                    break;
                case 2:
                    system("cls");
                    printf("\nAté logo!\n");

                    break;
            }

            break;
        case 3:
            printf("\nAté logo!\n");

            break;
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

void loop(int tentativas, char matriz1[6][6],char matriz2[6][6]){
        int a, b, i, j;

        puts("");
        do{
            puts("Insira a linha e a coluna da primeira peça: ");
            scanf("%d", &a );
            scanf("%d", &b);
        }while(a < 0 || a > 5 || b < 0 || b > 5);
       do{
            puts("Insira a linha e a coluna da segunda peça: ");
            scanf("%d", &i);
            scanf("%d", &j);
       }while(i < 0 || i > 5 || j < 0 || j > 5);
        tentativas++;
        compare(a, b, i, j, tentativas, matriz1, matriz2);
}

int compare(int a, int b, int i, int j, int tentativas, char matriz1[6][6], char matriz2[6][6]){
    int iguais, linha, coluna;
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
        puts("");
        printf("Tentativas até o momento: %d\n", tentativas);
        sleep(4);
        system("cls");
        for(linha = 0; linha <= 5; linha++){
            for(coluna = 0; coluna <= 5; coluna++){
                if(matriz2[linha][coluna] == matriz1[linha][coluna]){
                    iguais++;
                }
            }
        }
        if(iguais == 36){
            system("cls");
            printf("PARABÉNS! VOCÊ VENCEU!\n");
            printf("\nTotal de tentativas: %d\n", tentativas);
        }
        else{
            matrizjogo(6, matriz2, matriz1);
            loop(tentativas, matriz1, matriz2);
        }
    }

    else{
        puts("");
        puts("ERROU!");
        puts("");
        printf("Tentativas: %d\n", tentativas);
        matriz2[a][b] = temp1;
        matriz2[i][j] = temp2;
        sleep(4);
        system("cls");
        matrizjogo(6,matriz2,matriz1);
        loop(tentativas, matriz1,matriz2);
    }

return 0;
}