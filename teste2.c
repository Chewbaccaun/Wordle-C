#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char menu[8][6];
    int cont, cont2, contInterface, contInterface2;

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
            for(int checagemPalavra = 0; checagemPalavra < 1;)
            {
                printf("Digite uma palavra pelo amor de deus: ");
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