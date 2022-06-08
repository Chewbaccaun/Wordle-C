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
//**********************************************************//
//////////////////////////////////////////////////////////////
void PreencherMatriz(char menu[8][6])
{
    short int cont, cont2;

    for(cont = 1; cont < 7; cont++)
    {
        for(cont2 = 0; cont2 < 5; cont2++)
        {
            menu[cont][cont2] = '_';
        }
    }
}
//////////////////////////////////////////////////////////////
//**********************************************************//
//////////////////////////////////////////////////////////////
void DeterminarPalavra(char menu[8][6])
{
    char palavra[6] = "*****";
    short int i, cont, loop;
    system("clear");

    for(loop = 0; loop < 1;)
    {
        for(cont = 0; cont < 5; cont++)
        {
            printf(VERMELHO "\n\nDigite uma palavra da lingua portuguesa de 5 caracteres: ");
            __fpurge(stdin);
            scanf("%6s", palavra);

            for(i = 0; i < 5; i++) palavra[i] = toupper(palavra[i]); 
            
            if(palavra[0] == palavra[1] && palavra[1] == palavra[2] && palavra[2] == palavra[3] && palavra[3] == palavra[4])
            {
                system("clear");
                printf("Todas as letras sao iguais");
            }

            else

            if(palavra[0] == 'A' && palavra[1] == 'E' && palavra[2] == 'I' && palavra[3] == 'O' && palavra[4] == 'U')
            {
                system("clear");
                printf("AEIOU nao vale.");   
            }
        
            else

            if(strlen(palavra) != 5)
            {   
                system("clear");
                printf("Tamanho incorreto, digite novamente");
                palavra[5] = '/0';
            }
            
            else
            
            if(isalpha(palavra[0]) == 0 || isalpha(palavra[1]) == 0 || isalpha(palavra[2]) == 0 || isalpha(palavra[3]) == 0 || isalpha(palavra[4]) == 0 ) 
            {
                system("clear");
                printf ("Existem Caracteres invalidos, Digite Novamente");
            }

            else
            {
                for(i = 0; i < 5; i++)  menu[0][i] = palavra[i];
                loop = 1;
                break;
            }
        }
    }
}
//////////////////////////////////////////////////////////////
//**********************************************************//
//////////////////////////////////////////////////////////////
char VerificarVitoria(char menu[8][6], int a[7][5], int cont)
{
    char dnv[10];

    if (a[cont - 1][0] == 1 && a[cont - 1][1] == 1 && a[cont - 1][2] == 1 && a[cont - 1][3] == 1 && a[cont - 1][4] == 1)
    {
        printf(VERMELHO "Voce Acertou a palavra!!!\n\n");
        for(;;)
        {
            printf("Deseja jogar novamente?\nDigite 1 para jogar novamente ou 0 para encerrar o codigo: ");
            __fpurge(stdin);
            scanf("%c", &dnv[0]);
            if(dnv[0] == '1')
            {   
                for(int cont = 0; cont < 7; cont++)
                {
                    for(int cont2 = 0; cont2 < 5; cont2++)
                        {
                            menu[cont][cont2] = '_';
                        }
                }

                for(int cont = 0; cont < 8; cont++)
                {
                    for(int cont2 = 0; cont2 < 5; cont2++)
                    {
                        a[cont][cont2] = 0;
                    }
                }

                Game(menu, a);
                break;
            }
            else
            {
                if(dnv[0] == '0')
                {
                    __fpurge(stdin);
                    menu[7][4] = '5';
                    return menu;
                }
                else printf("Digito incorreto, tente novamente!\n");
            }
        }
    }
    else
    { 
        if(menu[6][4] != '_')
        {
            printf(VERMELHO "Voce Perdeu!!!\n\n");
            for(;;)
            {
                printf("Deseja jogar novamente?\nDigite 1 para jogar novamente ou 0 para encerrar o codigo: ");
                __fpurge(stdin);
                scanf("%c", &dnv[0]);
                if(dnv[0] == '1')
                {   
                    for(int cont = 0; cont < 7; cont++)
                    {
                        for(int cont2 = 0; cont2 < 5; cont2++)
                        {
                            menu[cont][cont2] = '_';
                        }
                    }

                    for(int cont = 0; cont < 8; cont++)
                    {
                        for(int cont2 = 0; cont2 < 5; cont2++)
                        {
                            a[cont][cont2] = 0;
                        }
                    }

                    Game(menu, a);
                    break;
                }
                else
                {
                    if(dnv[0] == '0')
                    {
                        __fpurge(stdin);
                        menu[7][4] = '5';
                        return menu;
                    }
                    else printf("Digito incorreto, tente novamente!\n");
                }
            }
        }
    }
}
//////////////////////////////////////////////////////////////
//**********************************************************//
//////////////////////////////////////////////////////////////
void AdicionarPalavra(int cont, char menu[8][6])
{
    if(menu[6][4] == '_')
    {
        for(int checagemPalavra = 0; checagemPalavra < 1;)
        { 
            printf(VERMELHO "Tente advinhar a palavra: \n");
            __fpurge(stdin);
            scanf("%6s", menu[cont]);
            for(int cont2 = 0; cont2 <= strlen(menu[cont]); cont2++) menu[cont][cont2] = toupper(menu[cont][cont2]);

            if(strlen(menu[cont]) != 5)
            {
                for(int zero = 0; zero < 8; zero++) menu[zero][5] = '\0'; 
                printf("Tamanho incorreto, digite novamente.\n");
                for(int buffer = cont + 1; buffer < 8; buffer++)
                {
                    for(int cont2 = 0; cont2 < 5; cont2++)
                    {
                        menu[buffer][cont2] = '_';
                    }
                }     
            }

            else

            if(menu[cont][0] == menu[cont][1] && menu[cont][1] == menu[cont][2] && menu[cont][2] == menu[cont][3] && menu[cont][3] == menu[cont][4]) printf("Todas as letras sao iguais\n");

            else

            if(menu[cont][0] == 'A' && menu[cont][1] == 'E' && menu[cont][2] == 'I' && menu[cont][3] == 'O' && menu[cont][4] == 'U') printf("AEIOU nao vale.\n");
                
            else    
            
            if(isalpha(menu[cont][0]) == 0 || isalpha(menu[cont][1]) == 0 || isalpha(menu[cont][2]) == 0 || isalpha(menu[cont][3] )  == 0 || isalpha(menu[cont][4] ) == 0)
            { 
                printf ("Existem Caracteres invalidos, Digite Novamente =(\n");
            }

            else
            {
                checagemPalavra = 1;
            }
        }
    }
}
//////////////////////////////////////////////////////////////
//**********************************************************//
//////////////////////////////////////////////////////////////
void Game(char menu[8][6], int a[7][5])
{
    short int cont, tentativas = 0;
    system("clear");
    PreencherMatriz(menu);
    DeterminarPalavra(menu);
 
    cont = 1;
    printf(BRANCO);

    for(;cont < 8; cont++)
    {
        imprimirMenu(menu, a);
        tentativas++;

        VerificarVitoria(menu, a, cont);

        if(menu[6][4] == '_' && menu[7][4] != '5')
        { 
            AdicionarPalavra(cont, menu);
            VerificarPalavra(tentativas, menu, a);
        }
        else
        {
            return;
        }
    }
}
//////////////////////////////////////////////////////////////
//**********************************************************//
//////////////////////////////////////////////////////////////
void VerificarPalavra(int tentativas, char menu[8][6], int a[7][5])
{
    short int cont, cont2;

    for(cont = 0; cont < 5; cont++)
    {
        for(cont2 = 0; cont2 < 5; cont2++)
        {
            if(menu[tentativas][cont] == menu[0][cont2])
            a[0][cont] = cont2;
        }
    }

    for(cont = 0; cont < 5; cont++)
    {
        if(menu[tentativas][cont] != menu[0][cont])
        a[tentativas][cont] = 0;
    }

    if(a[0][0] != a[0][1] && a[0][1] != a[0][2] && a[0][2] != a[0][3] && a[0][3] != a[0][4])
    {
        for(cont = 0; cont < 5; cont++)
        {
            for(cont2 = 0; cont2 < 5; cont2++)
            {
                if(menu[tentativas][cont] == menu[0][cont2] && a[tentativas][cont2] != 1 && a[tentativas][cont] != 1)
                {
                    a[tentativas][cont] = 2;
                }
            }
            if(menu[tentativas][cont] == menu[0][cont])
            a[tentativas][cont] = 1;
        }
    }
    else
    {
        for(cont = 0; cont < 5; cont++)
        {
            for(cont2 = 0; cont2 < 5 && cont2 != cont; cont2++)
            {
                if(menu[tentativas][cont] == menu[0][cont2] && a[tentativas][cont2] != 1 && a[tentativas][cont] != 1)
                {
                    a[tentativas][cont] = 2;
                }
                if(menu[tentativas][cont] == menu[tentativas][cont2] && cont2 != cont)
                {
                    a[tentativas][cont2] = 0;
                    cont++;
                }
            }
            if(menu[tentativas][cont] == menu[0][cont])
            a[tentativas][cont] = 1;
        }
    }

    for(cont = 0; cont < 5; cont++)
    {
        if(menu[tentativas][cont] == menu[0][cont])
        a[tentativas][cont] = 1;
    }
    a[tentativas + 1][0] = 0;
}
//////////////////////////////////////////////////////////////
//**********************************************************//
//////////////////////////////////////////////////////////////
void imprimirMenu(char menu[8][6], int a[7][5])
{
    __fpurge(stdin);
    system("clear");
    printf(BRANCO);
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

    printf(BRANCO);
}
//////////////////////////////////////////////////////////////
//**********************************************************//
//////////////////////////////////////////////////////////////
int main()
{
    system("clear");
    char op[10];
    char menu[8][6];
    int a[7][5] = {{0, 0, 0, 0, 0}};
    menu[7][4] = '2';
    printf(VERMELHON "\n\t\tTermo\n\n1 - Iniciar o Jogo\n0 - Encerrar o codigo\n\n");
    
    for(;op[0] != '0';)
    {
        printf(VERMELHO "Digite sua escolha para continuar: ");
        __fpurge(stdin);
        scanf("%c", &op[0]);

        if(op[0] == '1')
        {
            Game(menu, a);
            break;
        }
        else 
        {
            if(op[0] != '0')
            printf("\nOpcao invalida. Tente novamente\n");
        }

    }
    return 0;
}
//////////////////////////////////////////////////////////////
//**********************************************************//
//////////////////////////////////////////////////////////////
