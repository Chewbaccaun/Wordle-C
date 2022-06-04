#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define PRETO "\033[0;30m"
#define VERMELHON "\033[1;31m"
#define VERMELHO "\033[0;31m"
#define VERDE "\033[0;32m"
#define AMARELO "\033[0;33m"
#define AZUL "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CIANO "\033[0;36m"
#define BRANCO "\033[0;37m"
#define RESETAR "\033[0m"
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
char menu[7][6];
int a[7][5] = {{0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}};
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
void detPalavra()
{
    char palavra[6] = "*****";
    short int i;
    
    for(;;)
    {
        system("clear");
        printf("\nDigite uma palavra da lingua portuguesa de 5 caracteres: ");
        scanf("%6s", palavra );
        if(strlen(palavra) != 5)
        {
            printf("Tamanho incorreto, digite novamente: ");
            system("clear");
        }

        else    if (isalpha(palavra[0]) == 0 || isalpha(palavra[1]) == 0 || isalpha(palavra[2]) == 0 || isalpha(palavra[3]) == 0 || isalpha(palavra[4]) == 0 ) 
                {
                    printf ("Existem Caracteres invalidos, Digite Novamente  : ");
                }
                else break;
    }

    for(i = 0; i < 5; i++)
    {
        menu[0][i] = palavra[i];
        menu[0][i] = toupper(menu[0][i]); 
    }
}
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
void verPalavra(int tentativas)
{
    short int cont, cont2;

    for(cont = 0; cont < 5; cont++)
    {
        for(cont2 = 0; cont2 < 5; cont2++)
        {  
            if(menu[tentativas][cont] == menu[0][cont])
            a[tentativas][cont] = 1;  

            if(menu[tentativas][cont] == menu[0][cont2] && a[tentativas][cont2] != 1)
            a[tentativas][cont] = 2;
        }
    } 
}
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
void interfaceGames()
{
    short int cont, cont2, checagemPalavra, tentativas = 0;
    char dnv;
    
    system("clear");
    for(cont = 1; cont < 8; cont++)
    {
        for(cont2 = 0; cont2 < 5; cont2++)
        {
            menu[cont][cont2] = '*';
        }
    }
 
    cont = 1;
    printf(BRANCO);

    for(;cont < 8; cont++)
    {
        __fpurge(stdin);
        system("clear");
        for(int contInterface = 1; contInterface < 7; contInterface++)
        {
            for(int contInterface2 = 0 ;contInterface2 < 5; contInterface2++)
            {
                if(a[contInterface][contInterface2]==0)
 
                printf(BRANCO"%c   ", menu[contInterface][contInterface2]);
 
                else
                {
                    if(a[contInterface][contInterface2]==1)
 
                        printf(AZUL"%c   ", menu[contInterface][contInterface2]);
    
                    else
 
                        printf(AMARELO "%c   ", menu[contInterface][contInterface2]);
                }
            }
            printf("\n\n"); 
        }

        tentativas++;

        for (int contInterface3 = 0; contInterface3 < 6; contInterface3++)
        {
            if (a[contInterface3][0]== 1 && a[contInterface3][1]==1 && a[contInterface3][2]==1 && a[contInterface3][3]==1 && a[contInterface3][4]==1)
            {
                printf("Voce Acertou a palavra!!!\n\n");
                for(;;)
                {
                    printf("Deseja continar?\nDigite S para jogar novamente ou N para encerrar o codigo: ");
                    __fpurge(stdin);
                    scanf("%c", &dnv);
                    dnv = toupper(dnv);
                    if(dnv == 'S')
                    {   
                        for(cont = 0; cont < 8; cont++)
                        {
                            for(cont2 = 0; cont2 < 5; cont2++)
                            {
                                menu[cont][cont2] = '*';
                            }
                        }
                        for(cont = 0; cont < 8; cont++)
                        {
                            for(cont2 = 0; cont2 < 5; cont2++)
                            {
                                a[cont][cont2] = 0;
                            }
                        }
                        main();
                    }
                    else    if(dnv == 'N') return;
                            else printf("Digito incorreto, tente novamente!\n:");
                }
            }
        }

        if(menu[6][4] == '*')
        {
            for(checagemPalavra = 0; checagemPalavra < 1;)
            {  
                printf("Tente advinhar a palavra: \n");
                scanf("%6s", menu[cont]);
                __fpurge(stdin);
            
                if(strlen(menu[cont]) != 5)
                {
                    printf("Tamanho incorreto, digite novamente.\n");
                    for(int buffer = cont + 1; buffer < 7; buffer++)
                    {
                        for(cont2 = 0; cont2 < 5; cont2++)
                        {
                            menu[buffer][cont2] = '*';
                        }
                    }
                }
                
                else    if (isalpha(menu[cont][0]) == 0 || isalpha(menu[cont][1]) == 0 || isalpha(menu[cont][2]) == 0 || isalpha(menu[cont][3] )  == 0 || isalpha(menu[cont][4] ) == 0)
                        { 
                            printf ("Existem Caracteres invalidos, Digite Novamente =(\n");
                        }

                        else
                        {
                            for(cont2 = 0; cont2 < 5; cont2++) menu[cont][cont2] = toupper(menu[cont][cont2]);
                            checagemPalavra = 1;
                        }

                verPalavra(tentativas);
            }
        }
    }
}
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
int main()
{
    system("clear");
    char op = '9';
    printf(VERMELHON "\n\t\tTermo\n\n1 - Iniciar o Jogo\n0 - Encerrar o codigo\n\n");
    
    do
    {
        printf(VERMELHO "Digite sua escolha para continuar: ");
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

    __fpurge(stdin);  
    printf("\nCodigo encerrado, tchau.\n");
    return 0;
}
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
