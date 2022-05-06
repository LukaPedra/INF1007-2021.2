/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

/*
FUPQ calcule Prestação (R), Montante final (S), Principal inicial (P)
usando Juros (i) e período (n)
(1) S = P((1+i)^n)
(2) P = S/((1+i)^n)
(3) R = P (i(1+i)^n) / (((1+i)^n)-1)
(4) S = R(((1+i)^n)-1)/i

Crie um menu de opções que leia o número do cálculo, depois os valores envolvidos
e exiba o resultado correspondente
*/
#include <stdio.h>
#include <math.h>

int main()
{
    
    int opcao, periodo;
    float prestacao, montante, principalInicial, juros;
    
    printf("Qual a opcao de calculo de juros: ");           // calcule Prestação (R), Montante final (S), Principal inicial (P) usando Juros (i) e período (n)
    scanf("%d", &opcao);


    if (opcao == 1){
        
        printf("Principal inicial: ");                   
        scanf("%f", &principalInicial);
        
        printf("Juros: ");
        scanf("%f", &juros);
        
        printf("Periodo: ");
        scanf("%d", &periodo);
        
        montante = principalInicial * (pow((1 + juros), periodo));           //S = P((1+i)^n)
    }
    
    else if (opcao == 2){
        
        printf("Montante final: ");
        scanf("%f", &montante);
        
        printf("Juros: ");
        scanf("%f", &juros);
        
        printf("Periodo: ");
        scanf("%d", &periodo);
    
        principalInicial = montante / (pow((1 + juros), periodo));            //P = S/((1+i)^n);              
    }
    
    else if (opcao == 3){
        
        printf("Principal inicial: ");                   
        scanf("%f", &principalInicial);
        
        printf("Juros: ");
        scanf("%f", &juros);
        
        printf("Periodo: ");
        scanf("%d", &periodo);
        
        prestacao = principalInicial * (juros * (pow((1 + juros), periodo)) / ((pow((1 + juros), periodo)) - 1));                //R = P*(i(1+i)^n) / (((1+i)^n)-1)      
    }
    
    else if (opcao == 4){
        
        printf("Prestacao: ");
        scanf("%f", &prestacao);
        
        printf("Juros: ");
        scanf("%f", &juros);
        
        printf("Periodo: ");
        scanf("%d", &periodo);
        
        montante = prestacao * ((pow((1 + juros), periodo)) - 1) / juros;              //S = R*(((1+i)^n)-1)/i              calcule Prestação (R), Montante final (S), Principal inicial (P) usando Juros (i) e período (n)
    }
    
    return 0;
}

