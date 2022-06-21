#include <stdio.h>
#include <stdlib.h>

#define MAX 2
typedef struct
{
    int item[MAX];
    int inicio,fim;
} Fila;



//-------------------Função que inicia a Fila
void Inicia(Fila *F)
{
    F->inicio=F->fim=0;
}
//----------Função para inserir dados na Fila
int Insere(Fila *F,int X)
{
    if(F->fim==MAX)
        return 0;
    else
    {
        F->item[F->fim]=X;
        F->fim++;
        return 1;
    }
}

//----------Função para remover dados da Fila
int Remove(Fila *F,int *X)
{
    if(F->inicio==F->fim)
        return 0;
    else
    {
        X=F->item[F->inicio];
        F->inicio++;
        return 1;
    }
}

//----------Função para remover dados da Fila (com troca)
int RemoveTroca(Fila *F,int *X)
{
    if(F->inicio==F->fim)
        return 0;
    else
    {
        X=F->item[F->inicio];
        for(int i=0; i<MAX-1; i++)
            F->item[i]=F->item[i+1];
        F->fim--;
        return 1;
    }
}

void main()
{
    Fila F1;
    int i,retorno,valor;
    Inicia(&F1);
    for(i=0; i<MAX; i++)
    {
        printf("\nDigite um numero inteiro : ");
        scanf("%d",&valor);
        retorno=Insere(&F1,valor);
        if(retorno==1)
            printf("Dado inserido !!!\n");
        else
            printf("Fila esta cheia !!!\n");
        getch();
    }
    for(i=0; i<MAX; i++)
    {
        retorno=Remove(&F1,&valor);
        if(retorno==1)
            printf("\nRemovido: %d",valor);
        else
            printf("\nFila esta vazia !!!");
    }
    getch();

}


