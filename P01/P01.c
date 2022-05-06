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
    if(String == NULL){
        printf("Falta de memória\n");
		exit(1);
    }
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
	else if(opcao==1){
		for(int i=0;i<=strlen(String);i++){
			if(String[i]==c){
				contagem ++;
			}
			else{
				if (contagem == MaiorSeq){
					iLastSeq = i-contagem;
				}
				contagem = 1;
				c = String[i];
			}
			if(contagem>MaiorSeq){
				MaiorSeq = contagem;
				boolFirst = 0;
			}
		}		
		*posSeq = iLastSeq;
	}
  	else{
    	printf("Opção fora do alcance, escolha 1 para última ocorrência e 0 para primeira ocorrência!\n");
  }
    return MaiorSeq;
}
void copiarString(char* origem, char* destino,int len){
    if(*origem == '\0'){
        *destino = *origem;
        return;
    }
    if(len == 0){
        *destino = '\0';
        return;
    }
    *destino = *origem;
    copiarString(origem+1, destino+1, --len);
}
char * MontaString(char* String){
  	int x = strlen(String);
	  int * pos= (int*)malloc(sizeof(int));
  	int tam = sizeSeq(String,pos, 0);


    // para a primeira divisão
  	char * pedaco1 = malloc(*pos+1);
  	copiarString(String, pedaco1, *pos);

    int cmc = strlen(pedaco1) + tam;
    int fim = x - cmc;

  	char * pedaco2 = malloc(fim+1);
  	copiarString(String + *pos + tam, pedaco2, fim);


    // segunda divisão
    tam = sizeSeq(String,pos, 1);
    char * pedaco3 = malloc(*pos+1);
    copiarString(String, pedaco3, *pos);

    cmc = strlen(pedaco3) + tam;
    fim = x - cmc;
    char * pedaco4 = malloc(fim+1);
    copiarString(String + *pos + tam, pedaco4, fim);
    int tamfim = strlen(pedaco1) + strlen(pedaco2) + strlen(pedaco3) + strlen(pedaco4);
    char * strfinal = malloc(tamfim + 1);
    char * p1 = concatenastring(pedaco2,pedaco1);
    char * p2 = concatenastring(pedaco4,pedaco3);
    strfinal = concatenastring(p1,p2);
    free(pedaco1);
    //free(pedaco2);
    free(pedaco3);
    free(pedaco4);
    free(pos);
    return strfinal;
    }

char *concatenastring(char *s1, const char *s2)
{
    if((s1 == NULL) && (s2 == NULL))
        return NULL;
    char *start = s1;
    while(*start != '\0')
    {
        start++;
    }
    while(*s2 != '\0')
    {
        *start++ = *s2++;
    }
    return s1;
}
void teste(){
	
}