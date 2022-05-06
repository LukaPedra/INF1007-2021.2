/***********************************************************************
NOME COMPLETO: Lucca Vieira Rocha
MATRICULA PUC-Rio: 2011342
DATA: 21/10/2021
DISCIPLINA: INF1007    TURMA (33A, 33B, 33C, 33D):
DECLARACAO DE AUTORIA:
   Declaro que este documento foi produzido em sua totalidade por mim,
   sem consultas a outros alunos, professores ou qualquer outra pessoa.
************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *openFile(const char *file,const char * mode){
    return fopen(file,mode);
}
char **alocaVetor(int p, int t, float *media, int *nChar){
    char **Array, *palavra;
    int lenString;
    FILE *file;
    *nChar = 0;
    *media = 0;
    
    Array = (char**)malloc(p*sizeof(char*));
    if (Array == NULL){
        printf("Ocorreu um erro ao alocar a memória!\n");
        return NULL;
    }
    palavra = (char *)malloc((t+1) *sizeof(char*));
    if (palavra == NULL){
        printf("Ocorreu um erro ao alocar a memória!\n");
        return NULL;
    }
    file = openFile("T2entr2_33D_LuccaRocha_2011342.txt","r");
    if (file == NULL){
        printf("Ocorreu um erro ao abrir o arquivo!\n");
        return NULL;
    }
    while(fscanf(file, " %s", palavra)==1){
        lenString = strlen(palavra);
        Array[*nChar] = (char *)malloc((lenString+1) *sizeof(char*));
        *media += lenString;
        strcpy(Array[(*nChar)++],palavra);
    }
    fclose(file);
    *media /= *nChar;
    free(palavra);
    return Array;
}
void writeFile(char **Array, int nChar, float media){
    int i;
    FILE *file = openFile("T2saida_33D_LuccaRocha_2011342.txt","w");
    if (file == NULL){
        printf("Ocorreu um erro ao abrir o arquivo!\n");
        exit(1);
    }
    for ( i = 0; i < nChar; i++){
        if (strlen(Array[i])>media){
            fprintf(file, "%s\n", Array[i]);
        }
    }
    fclose(file);
}
void freeVetor(char **Array, int nChar){
    int i;
    for ( i = 0; i < nChar; i++){
        free(Array[i]);
    }
    free(Array);
}
int main (void){
    float media;
    int p,t,nChar,WordLen;
    char **ArrayPalavras;
    FILE *entr1 = openFile("T2entr1_33D_LuccaRocha_2011342.txt", "r");
    if (entr1 == NULL){
        printf("Ocorreu um erro ao abrir o arquivo!\n");
        exit(1);
    }


    fscanf(entr1, "%d %d",&p, &t);
    ArrayPalavras = alocaVetor(p,t, &media, &nChar);
    if (ArrayPalavras == NULL){
        printf("Ocorreu um erro ao alocar a memória!\n");
        exit(1);
    }
    writeFile(ArrayPalavras,nChar,media);
    freeVetor(ArrayPalavras,nChar);
    fclose(entr1);

    return 0;
}
