#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define CINCO 5
#define RESETAR  "\x1B[0m"      //SE [1;**m - Negrito
#define VERMELHO  "\x1B[31m" 
#define VERMELHON  "\x1B[1;31m"   //SE
#define VERDE  "\x1B[32m"
#define AMARELO  "\x1B[33m"
#define LARANJA  "\x1B[34m"
#define AZUL  "\x1B[35m"
#define CIANO  "\x1B[36m"
#define BRANCO  "\x1B[37m"

char menu[20][6] = {{"*****"}};
short int confirmadores[7][5] = {{1,1,1,1,1}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}};

void detPalavra()
{
    char palavra[6] = "*****";
    short int i;
    
    printf(VERDE "\nDigite uma palavra da lingua portuguesa de 5 caracteres: ");

    for(;;)
    {
        scanf("%s", palavra);
        if(strlen(palavra) != 5) printf("Tamanho incorreto, digite novamente: ");
        else break;
    }

    system("clear");
    
    for(i = 0; i < 5; i++)
    {
        menu[0][i] = palavra[i];
        menu[0][i] = toupper(menu[0][i]); 
    }
    printf(VERMELHO);
}

void verPalavra(int tentativas)
{
    short int cont, cont2;
    
    for(cont = 0; cont < CINCO; cont++)
    {
        for(cont2 = 0; cont2 < CINCO; cont2++)
        {
            if(menu[tentativas][cont] == menu[0][cont2]) confirmadores[tentativas][cont] = 2;
            if(menu[tentativas][cont] == menu[0][cont]) confirmadores[tentativas][cont] = 1;
        }
    }
}

void interfaceGames()
{
    short int cont, cont2, checagemPalavra, tentativas = 0;

    for(cont = 1; cont < 7; cont++)
    {
        for(cont2 = 0; cont2 < 5; cont2++)
        {
            menu[cont][cont2] = '*';
        }
    }
    
    printf(RESETAR);
    cont = 1;

    for(;cont < 8; cont++)
    {
        system("clear");
        
        for(int contInterface = 1; contInterface < 7; contInterface++)
        {
            for(int contInterface2 = 0 ;contInterface2 < CINCO; contInterface2++)
            {
                verPalavra(tentativas);
                if(confirmadores[contInterface][contInterface2] == 0) printf(BRANCO "%c   ", menu[contInterface][contInterface2]);
                else
                {
                    if(confirmadores[contInterface][contInterface2] == 1) printf(AZUL "%c   ", menu[contInterface][contInterface2]);
                    else printf(AMARELO "%c   ", menu[contInterface][contInterface2]);
                }
            }
            
            printf("\n\n");
        }
        
        tentativas++;

        if(menu[6][4] == '*')
        {
            for(;;)
            {
                printf("Tente advinhar a palavra: \n");
                scanf("%s", menu[cont]);

                if(strlen(menu[cont]) != 5)
                {
                    printf("Tamanho incorreto, digite novamente.\n");
                    for(int correcao = tentativas - 1; correcao < 7; correcao++)
                    {
                        for(cont2 = 0; cont2 < 5; cont2++)
                        {
                            menu[correcao][cont2] = '*';
                        }
                    }
                }
                else
                {
                    for(cont2 = 0; cont2 < 5; cont2++) menu[cont][cont2] = toupper(menu[cont][cont2]);
                    break;
                }
            }
        }
    }
}

int main()
{

    char op = '9';
    printf(VERMELHON "\n\t\tTermo\n\n1 - Iniciar o Jogo\n0 - Encerrar o codigo\n\n");
    
    do
    {
        printf("Digite sua escolha para continuar: ");
        scanf("%s", &op);

        if(op == '0') break;

        if(op != '1') printf("\nOpcao invalida. Tente novamente\n");
        else
        {
            detPalavra();
            interfaceGames();
            op = '0';
        }

    } while (op != '0');

    printf("\nVoce perdeu, tchau.\n");
    
    return 0;
}
