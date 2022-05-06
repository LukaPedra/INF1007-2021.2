#include <stdio.h>

int dif(int n1,int n2){
    int res = n1 - n2;

    if(res < 0){
        res = res * (-1);
    }
    return res;
}
int calculoConjunto(int qtd){
    int i;
    int MaiorDif=0;

    /*Variaveis de valores adjacentes percorrendo o conjunto*/
    int a,b;

    /*Variaveis dos valores com maior diferença absoluta entre si*/
    int Fa=0,Fb = 0;
    

    for (i=0;i<qtd;i++){
        if (i==0){
            printf("Digite um valor inteiro: ");
            scanf("%d",&a);
        }
        else{
            printf("Digite um valor inteiro: ");
            scanf("%d",&b);

            if(dif(a,b) > MaiorDif){
                if (dif(a,b)>100)
                {
                    printf("Valores adjacentes com maior diferenca absoluta: %d %d\n",a,b);
                    return 0;
                }
                else
                {
                MaiorDif=dif(a,b);
                Fa=a;
                Fb=b;
                }
            }
        a=b;
        }
    }
    printf("\tValores adjacentes com maior diferenca absoluta: %d %d\n",Fa,Fb);
}
int main(){
    int K;
    printf("Digite a quantidade de inteiros em cada conjunto: ");
    scanf("%d",&K);   
    for(int n = 1;n<4;n++){
        printf("Conjunto %d\n",n);
        calculoConjunto(K);
    }
    return 0;
}