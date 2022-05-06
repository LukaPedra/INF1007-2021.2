#include <stdio.h>
#include <stdlib.h>

struct Funcionario{
    char nome[81];
    int matricula;
    float salario; 
    Data dtNascimento;
    Data dtAdmissao;
};
typedef struct Data{
    int dia;
    int mes;
    int ano;
}Data;


int main(void){
    printf("\n");
}