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
//O código não está funcionando mas eu tentei... desde 14h até 23:49
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
void printEstoque(int qtdProd){
   Register vector[9000];
   FILE* StockBin = openFile("estoque.dat","rb");
   if(!StockBin)
    {
        printf("Arquivo nao e valido!\n");
        exit(1);
    }
   int j = 0;
   fread(&vector, sizeof(Register), qtdProd, StockBin);
   for (int i = 0; i < qtdProd; i++)
   {
      printf("codigo = %d preco = %.2f qtd = %d nome = %s\n",vector[i].code,vector[i].price, vector[i].qtd,vector[i].nome);
   }
   
}
void printPromo(Register *remedios, int product_num){
   Register *remedio = NULL;
   int i;
   int maxStock, maxPrice, MenCode;
   if (remedios == NULL || product_num == 0){
      puts("Não foi escolhido nenhum remedio para a promocao");
      return;
   }
   remedio = remedios;
   maxStock = remedio->qtd;
   maxPrice = remedio->price;
   MenCode = remedio->code;
   for (int i = 0; i < product_num; i++)
   {
      if (remedios[i].qtd<maxStock)
      {
         continue;
      }
      if (remedios[i].qtd==maxStock){
         if (remedios[i].price<maxPrice){
            continue;
         }
         else if(remedios[i].price==maxPrice){
            if (remedios[i].code<MenCode){
               continue;
            }
         }
      }
      remedio = (remedios+i);
      maxPrice = remedio->price;
      maxStock = remedio->qtd;
      MenCode = remedio->code;
   }
   printf("O remédio escolhido para promocao foi:\n Codigo:    %d\nPreco:     R$ %.2f\nQtd:     %d\nNome:      %s\n\n",remedio->code,remedio->price,remedio->qtd,remedio->nome);
   
}
Register* createVec(int* qtd){
   FILE* StockBin = openFile("estoque.dat", "rb");

   Register* tmp = (Register*)malloc(9000*sizeof(Register));
   if(!tmp){
	   printf("ocorreu um erro!");
	   exit(1);
   }
   while(!feof(StockBin)){
	   fread(tmp, sizeof(Register), 1, StockBin);
	   (*qtd)++;
   }
   (*qtd)--;
   return tmp;
}
void process(Register* remedios, int product_num){
   FILE* Vendas = openFile("vendas.txt", "r");
   int code, qtd;
   while(fscanf(Vendas," %d %d", &code,&qtd)>0){
      Register *remedio = findRemedio(remedios, product_num,code);
      if(!remedio)
         continue;
      remedio->qtd -= qtd;
      if (remedio->qtd<0)  
      {
         remedio->qtd = 0;
      }
      
   }
   fclose(Vendas);
}
void *buscaBin(Register* remedio, size_t min, size_t max, int code){
   size_t mid;
   if (max>=min){

   }
   mid = min + (max-1)/2;
   if(remedio[mid].code == code){
	   return &remedio[mid];
   }
   else if (remedio[mid].code < code){
	   return buscaBin(remedio, min, mid-1, code);
   }
   else if(remedio[mid].code>code){
	   return buscaBin(remedio, mid+1,max,code);
   }
}
Register* findRemedio(Register *remedios, int product_num, int code){
   return buscaBin(remedios, 0, product_num,code);
}
void sell() {
	register remedios[9000];
	int i, product_num;

	product_num = read_stock(remedios);
	if (product_num == -1)
		return;

	if (process_sales(remedios, product_num) == -1)
		return;

	show_promo_product(remedios, product_num);

	for (i = 0; i < product_num; ++i) {
		printf("código = %d\tpreço = %.2f\tqtd = %d\tnome = %s\n",
					remedios[i].code, remedios[i].price,
					remedios[i].quantity, remedios[i].name);
	}
}
void mainMenu(){
   int qtdProd;
   int input;
   FILE* Stock = openFile("T3entr1_33D_LuccaRocha_2011342.txt","r");
   Register* tmp;

   printf("Digite o numero da opção desejada: \n1 - Montar estoque \n2 - Imprimir estoque\n3 - Vender\n4 - Sair\n\n");
   scanf("%d", &input);
   while(1){
      switch (input)
      {
         case 1:
         {
            qtdProd = montaEstoque(Stock);
            break;
         }
         case 2:
         {
            printEstoque(qtdProd);
            break;
         }
         case 3:
         {
            sell();
            break;
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