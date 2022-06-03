#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define RESETAR   "\x1B[0m"      //SE [1;**m - Negrito
#define VERMELHO  "\x1B[3;35m"   
#define VERDE     "\x1B[32m"
#define AMARELO   "\x1B[33m"
#define LARANJA   "\x1B[31m"
#define AZUL      "\x1B[34m"
#define CIANO     "\x1B[36m"
#define BRANCO    "\x1B[37m"

//////////////////////////////////////////////////////////////

char menu[8][6];
int a[7][5];

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

void verPalavra(int tentativas)
{
    short int cont, cont2;

    for(cont = 0; cont < 5; cont++)
    {

        for(cont2 = 0; cont2 < 5; cont2++){

        if(menu[tentativas][cont] == menu[0][cont2])
        a[tentativas][cont] = 2;

        if(menu[tentativas][cont] == menu[0][cont])
        a[tentativas][cont] = 1;  
        }
    } 
}

//////////////////////////////////////////////////////////////

void interfaceGames()
{
    short int cont, cont2, checagemPalavra, tentativas = 0;
    int ped = 0;

    system("clear");
    for(cont = 1; cont < 8; cont++)
    {
        for(cont2 = 0; cont2 < 5; cont2++)
        {
            menu[cont][cont2] = '*';
        }
    }
 
    cont = 1;
 
    for(;cont < 7; cont++)
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
 
                        printf(AMARELO"%c   ", menu[contInterface][contInterface2]);
                }
            }

            for (int contInterface3 = 0; contInterface3 < 6; contInterface3++)
            {
                if (a[contInterface3][0]== 1 && a[contInterface3][1]==1 && a[contInterface3][2]==1 && a[contInterface3][3]==1 && a[contInterface3][4]==1   )
                {
                    ped++;
                    break;
                }
            }
 
            if (ped == 1)
            {
                break;
            } 

        printf("\n\n"); 
        }
        
          
        if (ped == 1)
            {
                printf (VERDE "\n PARABUAIS VOCE' ACERTOU =) ");
                return 0;
            }

        tentativas++;

        if(menu[6][4] == '*')
        {
 
            for(checagemPalavra = 0; checagemPalavra < 1;)
            {
                
                printf("Tente advinhar a palavra: \n");
                scanf("%s", menu[cont]);
            
                if(strlen(menu[cont]) != 5)
                {
                    printf("Tamanho incorreto, digite novamente.\n");
                }
            
             
                else if (isalpha(menu[cont][0]) == 0 || isalpha(menu[cont] [1]) == 0 || isalpha(menu[cont] [2]) == 0 || isalpha(menu[cont] [3] )  == 0 || isalpha(menu[cont] [4] )  == 0)
                { 
                printf ("Existem Caracteres invalidos, Digite Novamente =( : ");
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

int main()
{
    char op = '9';
    printf(VERMELHO "\n\t\tTermo\n\n1 - Iniciar o Jogo\n0 - Encerrar o codigo\n\n");
    
    do
    {
        printf(BRANCO "Digite sua escolha para continuar: ");
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
