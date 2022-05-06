#include <stdio.h>


int main()
{
    unsigned int x = 0xFFFFFFBB;

    printf("decimal interpretado como inteiro sem sinal: %.u\n", x);

    printf("inteiro com sinal: %d\n", x);

    printf("endereco da variavel: %p\n", &x);

    return 0;
}