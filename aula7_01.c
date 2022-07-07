#include <stdio.h>
#include <stdlib.h>

/*1) Faça uma alteração na função de remoção do
final da lista, para que esta exclua a lista toda.*/

typedef struct no
{
    int dados;
    struct no *prox;
} noptr;
noptr *inicio;

void insere_lista(noptr *novo, int valor)
{
    noptr *p;
    novo->dados=valor;
    novo->prox = NULL;
    if(inicio==NULL)
        inicio=novo;
    else
    {
        p=inicio;
        while(p->prox!=NULL)
            p=p->prox;
        p->prox=novo;
    }
}

void remove_lista()
{
    noptr *p, *ant;
    if(inicio==NULL)
    {
        printf("\nLista Vazia!!!");
        return;
    }
    else
    {
        p=inicio;
        ant=p;
        while(inicio!=NULL)
        {
            p=inicio;
            printf("\nValor Removido: %d",p->dados);
            inicio=p->prox;
            free(p);
        }
    }
}

void lista_todos()
{
    if(inicio==NULL)
    {
        printf("\nLista Vazia!!!");
        return;
    }
    noptr *p;
    p = inicio;
    while(p)
    {
        printf("\nDado: %d",p->dados);
        p = p->prox;
    }
    printf("\n");
}

void main()
{
    int resp=-1;
    inicio=NULL;
    noptr *info;
    int dados;
    do
    {
        printf("\n Menu\n1 Inserir no final; \n2 Apagar todos os elementos da lista \n3 Listar dados \n0 Sair \n");
        scanf("%d",&resp);
        if(resp == 1)
        {
            printf("\nDigite um numero: ");
            scanf("%d",&dados);
            info=(struct no *) malloc(sizeof(noptr));
            if(!info)
            {
                printf("\nSem Memoria!!!");
                return;
            }
            insere_lista(info,dados);
        }
        else if(resp == 2)
        {
            remove_lista();
        }
        else if(resp==3)
        {
            lista_todos();
        }
        else if(resp == 0)
        {
            printf("\nSaindo");
        }
        else
        {
            printf("\nComando invalido");
        }
    }
    while(resp!=0);
}
