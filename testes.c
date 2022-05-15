#include <stdio.h>
#include <stdlib.h>

int main()
{
    char menu[6][6];
    int cont, cont2;

    for(int cont = 0; cont < 5; cont++)
    {
        for(int cont2 = 0; cont2 < 5; cont2++)
        {
            menu[cont][cont2] = 'a';
        }
    }

    cont = 0; cont2 = 0;
    do
    {
    for(int contInterface = 0; contInterface < 5; contInterface++)
    {
        for(int contInterface2 = 0 ;contInterface2 < 5; contInterface2++)
        {
            printf("\t%c ", menu[contInterface][contInterface2]);
        }
        printf("\n");
    }

    for(;cont < 5; cont++, cont2++)
    {
            printf("Digite a palavra: ");
            scanf("%s", &menu[cont]);
    }
    } while(cont != 5);
}
