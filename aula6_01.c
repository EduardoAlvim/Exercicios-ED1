#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Faça um programa que implemente uma lista encadeada
de dados. Os dados são: nome (char 30), idade (inteiro) e
ponteiro para o próximo.
• Implemente as seguintes funções:
• Inserir no início;
• Mostrar todos;
• Apagar o primeiro elemento da lista
• Enviar um nome para a função, se existir, aumentar
a idade em 10 anos.
*/

typedef struct no
{
    char nome[30];
    int idade;
    struct no *prox;
} noptr;
noptr *inicio;

void insere_lista(noptr *novo, int i, char n[])
{
    novo->idade=i;
    strcpy(novo->nome,n);
    if(inicio==NULL)
        novo->prox = NULL;
    else
        novo->prox=inicio;
        inicio=novo;
}

void remove_lista()
{
    noptr *p;
    if(inicio==NULL)
    {
        printf("\nLista Vazia!!!");
        return;
    }
    else
    {

        p=inicio;
        printf("\nNo removido: %s \n %d",p->nome,p->idade);
        inicio=p->prox;
        free(p);

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
        printf("\nNome: %s\nIdade: %d",p->nome,p->idade);
        p = p->prox;
    }
    printf("\n");
}

void aumenta_idade(char n[])
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
        if(strcmp(p->nome,n) == 0)
        {
            p->idade = p->idade +10;
        }
        p=p->prox;
    }
    printf("\n");
}

void main()
{
    int resp=-1;
    inicio=NULL;
    noptr *info;
    int idade;
    char nome[30];
    do
    {
        printf("\n Menu\n1 Inserir no inicio; \n2 Mostrar todos; \n3 Apagar o primeiro elemento da lista\n4 Enviar um nome para aumentar a idade em 10 anos;\n0 Sair \n");
        scanf("%d",&resp);
        if(resp == 1)
        {
            printf("\nDigite seu nome: ");
            fflush(stdin);
            gets(nome);
            fflush(stdin);
            printf("\nDigite sua idade: ");
            scanf("%d",&idade);
            info=(struct no *) malloc(sizeof(noptr));
            if(!info)
            {
                printf("\nSem Memoria!!!");
                return;
            }
            insere_lista(info,idade,nome);
        }
        else if(resp == 2)
        {
            lista_todos();
        }
        else if(resp == 3)
        {
            remove_lista();
        }
        else if(resp == 4)
        {
            printf("\nDigite um nome: ");
            fflush(stdin);
            gets(nome);
            aumenta_idade(nome);
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
