#include <stdio.h>
#include <stdlib.h>

float parcela(float valor, float* parcela_valor,int* nParcelaram){
    int parcelas;

    if((valor<=100000.0)&&(valor>=200.0)){
        if(valor>6000){
            (*parcela_valor)=valor/60;
            parcelas = valor/(*parcela_valor);

        }
        else if (valor <=6000)
        {
            
            parcelas = valor/100;
            (*parcela_valor)=valor/parcelas;

        }
        (*nParcelaram)++;
    }
    else{
        printf("NAO PODE PARCELAR\n");
        return 0.0;
    }
    return parcelas;
}

int main(void){
    float valor;
    float parcela_valor;
    int codigoCliente;
    int Running = 1;
    int nDevedores = 0;
    int nParcelaram = 0;

    while(Running){
        printf("Digite o numero do devedor: ");
        scanf("%d",&codigoCliente);
        if (codigoCliente==0)
        {
            Running=0;
        }
        else
        {
            nDevedores++;
            printf("Digite o valor da dívida: ");
            scanf("%f", &valor);
            int resultado = parcela(valor, &parcela_valor, &nParcelaram);
            if (resultado==0.0){
                printf("\n");
                continue;
            }
            printf("\nCodigo: %d \t Divida: R$%.2f \nNumero de parcelas: %d \t Valor da parcela: %.2f\n\n",codigoCliente,valor,resultado,parcela_valor);
        }
    }
    printf("\nTotal de devedores: %d\tPuderam parcelar divida: %d\n",nDevedores,nParcelaram);
}