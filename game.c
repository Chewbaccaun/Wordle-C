#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include </Home/Chewbaccaun>
#define RESETAR  "\x1B[0m"      //SE [1;**m - Negrito
#define VERMELHO  "\x1B[31m"    //SE
#define VERDE  "\x1B[32m"
#define AMARELO  "\x1B[33m"
#define LARANJA  "\x1B[34m"
#define AZUL  "\x1B[3;35m"
#define CIANO  "\x1B[36m"
#define BRANCO  "\x1B[37m"

char menu[8][6];

void detPalavra()
{
    char palavra[6] = "*****";
    short int i;
    
    printf("\nDigite uma palavra da lingua portuguesa de 5 caracteres: ");

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
}

void interfaceGames()
{
    short int cont, cont2, contInterface, contInterface2, checagemPalavra;

    for(cont = 1; cont < 8; cont++)
    {
        for(cont2 = 0; cont2 < 5; cont2++)
        {
            menu[cont][cont2] = '*';
        }
    }

    cont = 1;

    for(;cont < 8; cont++)
    {
        system("clear");
        
        for(contInterface = 0; contInterface < 7; contInterface++)
        {
            for(contInterface2 = 0 ;contInterface2 < 5; contInterface2++) printf("%c   ", menu[contInterface][contInterface2]);
            printf("\n\n");
        }

        if(menu[7][4] == '*')
        {
            for(checagemPalavra = 0; checagemPalavra < 1;)
            {
                printf("Tente advinhar a palavra: \n");
                scanf("%s", menu[cont]);

                if(strlen(menu[cont]) != 5)
                {
                    printf("Tamanho incorreto, digite novamente.\n");
                }
                else
                {
                    for(cont2 = 0; cont2 < 5; cont2++) menu[cont][cont2] = toupper(menu[cont][cont2]);
                    checagemPalavra = 1;
                }
            }
        }
    }
}

/*
void game()
{
    short int cont, cont2, chances = 0, posicionador = 1, ganhar;
    
    printf("Tente adivinhar a palavra: ");
    scanf("%s", &tentativa);
        
    if(tentativa[5] != '\0') printf("Palavra grande demais, digite novamente: ");
    else
    {
        ganhar = strcmp(palavra,tentativa); 
        system("clear");
        for(cont = 0; cont < 5; cont++)
        {
            if(ganhar == 0)
            {
                system("clear");
                printf("Acertou miseravi");
                chances = 5;
                return 0;
            }
            else
            {
                if(tentativa[cont] == palavra[cont]) printf("A letra %c esta correta \n", tentativa[cont]);
            }
        }
    }
    posicionador++;
    chances++;
}
*/

int main()
{
    char op = '9';
    printf(AZUL "\n\t\tTermo\n\n1 - Iniciar o Jogo\n0 - Encerrar o codigo\n\n");
    
    do
    {
        printf(AZUL "Digite sua escolha para continuar: ");
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

    system("clear");
    printf("\nCodigo encerrado, tchau.\n");
    
    return 0;
}