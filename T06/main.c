#include <stdio.h>
#include <stdlib.h>

void maxmin(int *vet,int vet_len, int *min, int *max);
void printIntArray(int *vet, int vet_len);
int *ordenar(int *vet, int vet_len, int *sort_len);

int main (void){
    int sort_len, *sort_vet;
    int vet_len = 9;
    int vet[] = {4, 2, 7, 5, 2, 3, 9, 13, 4};
    int vet2[]={5};
    int vet2_len = 1;
 
    printIntArray(vet,vet_len);
    sort_vet = ordenar(vet, vet_len, &sort_len);
    printIntArray(sort_vet,sort_len);

    printIntArray(vet2,vet2_len);
    sort_vet = ordenar(vet2, vet2_len, &sort_len);
    printIntArray(sort_vet,sort_len);
    return 0;
}
void maxmin(int *vet,int vet_len, int *min, int *max){
    int i;

    *min = vet[0];
    *max = vet[0];

    for(i=1 ; i<vet_len ; i++){
        if(vet[i]>(*max)){
            *max = vet[i];
        }
        if(vet[i]<(*min)){
            *min = vet[i];
        }
    }
}
void printIntArray(int *vet, int vet_len){
    int i;
    printf("[ ");
    for(i=0; i < vet_len-1; i++){
        printf("%d, ",vet[i]);
    }
    printf("%d ]\n",vet[i]);
}
int *ordenar(int *vet,int vet_len, int *sort_len){
    int i, min, max, *sort_vet;

    maxmin(vet, vet_len, &min, &max);
    *sort_len = max - min+1;

    sort_vet = (int *)malloc(sizeof(int)* *sort_len);
    if (!sort_vet)
    {
        return NULL;
    }
    sort_vet[0]= min;
    sort_vet[*sort_len-1]=max;
    for ( i = 1; i < (*sort_len)-1; i++)
    {
        sort_vet[i]=sort_vet[i-1]+1;
    }
    return sort_vet; 
}