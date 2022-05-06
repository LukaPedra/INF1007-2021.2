#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void checkMalloc(void* ptr)
{
    if(ptr == NULL)
    {
        printf("Falta de espaço da memoria\n");
        exit(1);
    }
}

char* getInit(char* name)
{
    int i = 0;
    int j = 0;
    int w = 1;
    int initCount = 1;

    while(*(name + i) != '\0')
    {
        if(*(name + i) == ' ')
        {
            initCount++;
        }
        i++;
    }

    char* init = (char*)malloc(initCount*sizeof(char));
    checkMalloc(init);

    *(init + 0) = *(name + 0);

    while(*(name + j) != '\0')
    {
        if(*(name + j) == ' ')
        {
            *(init + w) = *(name + j + 1);
            w++;
        }
        j++;
    }

    *(init + initCount) = '\0';

    return init;
}

int main(void)
{
    char* hub = (char*)malloc(100*sizeof(char)+1);
    checkMalloc(hub);

    char c;

    char* name;
    char* date;
    char* mName;

    int index = 0;

    printf("Insira o seu nome: ");

    while((c = getchar()) != '\n')
    {
        *(hub + index) = c;
        index++;
    }
    *(hub + index++) = '\0';

    name = &*(hub + 0);

    printf("Insira a data de nascimento (dd/mm/aaaa): ");

    while((c = getchar()) != '\n')
    {
        *(hub + index) = c;
        index++;
    }
    *(hub + index++) = '\0';

    int dateIndex = index - 11;

    int mNameIndex = index;

    date = &*(hub + dateIndex);

    printf("Insira o nome da mae: ");

    while((c = getchar()) != '\n')
    {
        *(hub + index) = c;
        index++;
    }
    *(hub + index++) = '\0';

    mName = &*(hub + mNameIndex);

    printf("%p - %s\n", name, name);
    printf("%p - %s\n", date, date);
    printf("%p - %s\n", mName, mName);

    for(int i = 0; i < index; i++)
    {
        printf("%c", hub[i]);
    }
    printf("\n");
    return 0;
}