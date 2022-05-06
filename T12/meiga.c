#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct PoligonoRegular{
    int nLados;
    float lado;
    char* cor;
}Poligon;

Poligon* createPol(char* poligonoNome, float lado, char* cor)
{
    Poligon* poli = (Poligon*)malloc(sizeof(Poligon));
    if(poli==NULL){
        printf("Ocorreu um erro ao tentar alocar a memória! \n");
        exit(1);
    }
    if(poligonoNome == "TRIANGULO"){
        poli->nLados = 3;
    }
    else if(poligonoNome == "QUADRADO"){
        poli->nLados = 4;
    }
    else if(poligonoNome == "HEXAGONO"){
        poli->nLados = 6;
    }
    poli->lado = lado;
    poli->cor = (char*)malloc(strlen(cor));
    if(!poli->cor){
        printf("Ocorreu um erro ao tentar alocar a memória!");
        exit(1);
    }
    strcpy(poli->cor, cor);

    return poli;
}

void printPol(Poligon* poli){
    if(poli == NULL){
        printf("Ocorreu um erro ao tentar acessar este endereco de memoria!\n");
        return;
    }
    printf("%d %.2f %s\n", poli->nLados, poli->lado, poli->cor);
}

void calculateArea(Poligon* poli){
    float area;
    
    if(!poli){
        printf("Ocorreu um erro ao tentar acessar este endereco de memoria!\n");
        return;
    }

    if(poli->nLados == 3){
        area = (sqrt(3) * poli->lado * poli->lado)/4;
    }
    
    if(poli->nLados == 4){
        area = poli->lado * poli->lado;
    }

    if(poli->nLados == 6){
        area = (poli->lado * poli->lado * 3 * sqrt(3))/2;
    }

    printf("AREA: %.1f\n", area);
}

int main(void) {
    Poligon* Quad = createPol("QUADRADO", 10.0, "AZUL");
    printPol(Quad);
    calculateArea(Quad);
    free(Quad ->cor);
    free(Quad);

    Poligon* Tri = createPol("TRIANGULO", 7.5, "ROSA CHOQUE");
    printPol(Tri);
    calculateArea(Tri);
    free(Tri->cor);
    free(Tri);

    Poligon* Hexa = createPol("HEXAGONO",12,"AZUL MARINHO");
    printPol(Hexa);
    calculateArea(Hexa);
    free(Hexa->cor);
    free(Hexa);
    return 0;
}