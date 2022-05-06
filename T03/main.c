#include <stdio.h>

float desconto(float valor, float porcentagem){
    return (valor * porcentagem);
}
int main(void)
{
    int qtd;
    float preco;
    float desconto_quantidade, desconto_montante, precoFinal;
    int caso = 0;

    printf("insira a quantidade comprada do produto: ");
    scanf("%d",&qtd);
    printf("insira o valor unitário do produto comprado: ");
    scanf("%f", &preco);

    float resultado = preco * (float)qtd;
    /*ajuda a fazer o print final*/
    float aux = resultado;

    if (qtd > 15){
        desconto_quantidade = desconto(resultado,0.1);
        resultado = resultado - desconto_quantidade;
        caso=caso +1;
    }
    if (aux>100){
        desconto_montante = desconto(resultado, 0.2);
        resultado = resultado - desconto_montante;
        caso=caso+2; 
    }
    printf("\nTotal Compra: %.2f \n ", aux);
    if (caso == 1){
        printf("Desconto pelas unidades: %.2f (10%% de %.2f) \n",desconto_quantidade, aux);
    }
    else if (caso == 2){
        printf("Desconto pelo montante: %.2f (20%% de %.2f)\n", desconto_montante, aux);
    }
    else if (caso == 3){
        printf("Desconto pelas unidades: %.2f (10%% de %.2f) \n",desconto_quantidade, aux);
        printf("Desconto pelo montante: %.2f (20%% de %.2f(%.2f - %.2f))\n",desconto_montante, aux - desconto_quantidade, aux, desconto_quantidade);
    }
    printf("Total a pagar: %.2f\n", resultado);
    return 0;
}
