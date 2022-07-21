#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no
{
    char dados;
    struct no *ant;
    struct no *prox;
};
typedef struct no noptr;

void insere_lista(noptr **inicio, noptr *novo, char d)
{
    novo->dados=d;
    novo->ant=NULL;
    if(*inicio==NULL)
        novo->prox = NULL;
    else
    {
        novo->prox=*inicio;
        (*inicio)->ant=novo;
    }
    *inicio=novo;
}

int palindromo(noptr *inicio)
{
    noptr *i;
    noptr *f;
    i=inicio;
    f=inicio;
    int cont=0;
    while(f->prox != NULL)
    {
        f=f->prox;
    }
    while(f->ant != i->prox)
    {
        if(i->dados != f->dados)
            cont++;
        f=f->ant;
        i=i->prox;
    }
    if(cont==0)
        return 0;
    else
        return 1;
}

void main()
{
    noptr *inicio;
    int resp=-1;
    inicio=NULL;
    noptr *info;
    char str[1000];
    gets(str);
    for(int i=0; i<strlen(str); i++)
    {
        info=(struct no *) malloc(sizeof(noptr));
        if(!info)
        {
            printf("\nSem Memoria!!!");
            return;
        }
        if(str[i]!= ' ')
            insere_lista(&inicio,info,str[i]);
    }
    printf("\n %d",palindromo(inicio));
}
