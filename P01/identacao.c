#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copiarString(char* origem, char* destino,int len);
int sizeSeq(char* String,int* posSeq, int opcao);
char * MontaString(char* String);
char *concatenastring(char *s1, const char *s2);

int main(void){
    char string[] ="asdfg\n";
    char * strfinal = MontaString(string);
    printf("%s",strfinal);
  	free(strfinal);
	return 0;
}
int sizeSeq(char* String,int* posSeq,int opcao){
    int contagem=0;
    int MaiorSeq = 0;
    int iFirstSeq, iLastSeq=0;
    int boolFirst;

    char c = String[0];
    if(opcao==0){
		boolFirst=0;
		for(int i=0;i<strlen(String);i++){
			if(String[i]==c){
				contagem ++;
            }
            else{
                if (contagem == MaiorSeq){
					    if(boolFirst == 0){
						      iFirstSeq = i-contagem;
						      boolFirst = 1;
					    }
				  }
            }
            contagem = 1;
			c = String[i];
        }
        if(contagem>MaiorSeq){
				MaiorSeq = contagem;
				boolFirst = 0;
		}
    }
    *posSeq = iFirstSeq;
}