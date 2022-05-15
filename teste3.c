#define RESETAR  "\x1B[0m"
#define VERMELHO  "\x1B[31m"
#define VERDE  "\x1B[32m"
#define AMARELO  "\x1B[33m"
#define AZUL  "\x1B[34m"
#define MAGENTA  "\x1B[35m"
#define CIANO  "\x1B[36m"
#define BRANCO  "\x1B[37m"

int main()
{
    printf("%sred\n", VERMELHO);
    printf("%sgreen\n", VERDE);
    printf("%syellow\n", AMARELO);
    printf("%sblue\n", AZUL);
    printf("%smagenta\n", MAGENTA);
    printf("%scyan\n", CIANO);
    printf("%swhite\n", BRANCO);
    printf("%snormal\n", RESETAR);

    return 0;
}