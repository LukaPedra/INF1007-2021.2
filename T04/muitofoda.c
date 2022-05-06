#include <stdio.h>




int diff(int a, int b){
    int r = a-b;

    if (r < 0){
      r = r*(-1);  
    }
    return r;
}

void loop(int qtd){
    int i = 0;
    int a,b;
    int aux = 0;
    
    int n1,n2;

    int maiorDif = 0;
    

    while(i<(qtd-1)){
        
        if(i>100){
          printf("ERRO: EXCEDEU MAIS DE 100 VALORES");
          break;
        }

        if(aux == 0){
            printf("Digite seu número: ");
            scanf("%d",&a);
            printf("Digite seu número:");
            scanf("%d",&b);
            aux = 1;
        }
        
        else if(i%2 == 0 && aux == 1){
            printf("Digite seu número: ");
            scanf("%d",&b);

        }
        else if(i%2 == 1 && aux == 1){
            printf("Digite seu número: ");
            scanf("%d",&a);
        }

        if(diff(a,b) > maiorDif){
            maiorDif = diff(a,b);
            n1 = a;
            n2 = b;
        }
        
        i++;
    }

  printf("Maior diff adjacente: %d\n",maiorDif);
  printf("Números: %d e %d\n",n1,n2);
}



int main (void){
    int qtd;


    for(int k = 1;k<4;k++){
      printf("\nConjunto %d\n\n",k);
      printf("Digite a quantidade: ");
      scanf("%d",&qtd);
      loop(qtd);
    }

    return 0;
}