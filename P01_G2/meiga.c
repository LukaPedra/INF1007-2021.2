 /***********************************************************************
NOME COMPLETO: Lucca Vieira Rocha
MATRICULA PUC-Rio: 2011342
DATA: 18/11/2021
DISCIPLINA: INF1007    TURMA (33A, 33B, 33C, 33D): 33D
DECLARACAO DE AUTORIA:
   Declaro que este documento foi produzido em sua totalidade por mim, sem consultas a outros alunos, professores ou qualquer outra pessoa.
************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#define 
typedef struct Register
{
   int code;
   float price;
   int qtd;
   char nome[87];
}Register;

FILE* openFile(const char* path, const char* mode)
{
    FILE* file = fopen(path, mode);

    if(!file)
    {
        printf("Arquivo nao e valido!\n");
        exit(1);
    }

    return file;
}

int montaEstoque(FILE* Stock){

   FILE* StockBin = openFile("estoque.dat","wb");
   int qtdProd = 0;
   Register tmp[9000];
   int x = 1;

   while(!feof(Stock))
   {
      fscanf(Stock, "%d %f %d %[^\n]", &tmp[qtdProd].code,&tmp[qtdProd].price,&tmp[qtdProd].qtd,tmp[qtdProd].nome);
      printf("%d %f %d %s\n", tmp[qtdProd].code,tmp[qtdProd].price,tmp[qtdProd].qtd,tmp[qtdProd].nome);
      qtdProd++;
   }
   while(x<=1){
      fwrite(tmp,sizeof(tmp),1,StockBin);
      x++;
   }
   
   fclose(StockBin);
   fclose(Stock);
   return qtdProd;
}

Register* printEstoque(int qtdProd){
   printf("hello there");	
   Register* vector = (Register*)malloc(sizeof(Register)*9000);
   FILE* StockBin = openFile("estoque.dat","rb");
   int j = 0;

   /*for (int h = 0; h < 9000; h++)
   {
      vector[h]=NULL;
   }*/
   /*while(fread(&vector,sizeof(vector),1,StockBin)==1){
      printf("codigo = %d preco = %.2f qtd = %d nome = %s\n",vector[j]->code,vector[j]->price, vector[j]->qtd,vector[j]->nome);
      j+.
   }*/
   
   fread(&vector,sizeof(vector),1,StockBin);
   for (int i = 0; i < qtdProd; i++)
   {
      printf("codigo = %d preco = %.2f qtd = %d nome = %s\n",vector[i].code,vector[i].price, vector[i].qtd,vector[i].nome);
   }
   return vector;
}
void Sell(){

}
void mainMenu(){
   Register vector[9000];
   int qtdProd;
   int input;
   FILE* Stock = openFile("estoque.txt","r");
   Register* tmp;

   printf("Digite o numero da opção desejada: \n1 - Montar estoque \n2 - Imprimir estoque\n3 - Vender\n4 - Sair\n\n");
   scanf("%d", &input);
   while(1){
      switch (input)
      {
         case 1:
         {
            qtdProd = montaEstoque(Stock);
         }
         case 2:
         {
            printEstoque(qtdProd);
         }
         case 3:
         {
            Sell();
         }
         case 4:
         {
            exit(1);
         }
         default:{
            printf("Digite um numero valido!!");
            break;
         }
      }
      scanf("%d",&input);
   }
   fclose(Stock);
}
int main (void){
   mainMenu();
   return 0;
}