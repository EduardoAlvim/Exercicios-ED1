#include <stdio.h>
#include <conio.h>
struct stack
{
    int topo;
    int dados[10];
};
void empilha (int x, struct stack *pilha);
int desempilha(struct stack *pilha);

void main(void)
{
    int x;
    struct stack p1;
    p1.topo=-1;
    empilha(4, &p1);
    empilha(2, &p1);
    empilha(7, &p1);
    x=desempilha(&p1);
    printf("\n %d",x);
    x=desempilha(&p1);
    printf("\n %d",x);
    x=desempilha(&p1);
    printf("\n %d \n",x);
    x=desempilha(&p1);
    printf("\n %d \n",x);
}

void empilha (int x, struct stack *pilha)
{
    if (pilha->topo == 9)
    {
        /* pilha cheia*/printf("%s", "stack overflow");
    }
    else
    {
        pilha->topo = pilha->topo +1;
        pilha->dados[pilha->topo]=x;
    }
}
int desempilha(struct stack *pilha)
{
    int x;
    if (pilha->topo == -1)
    {
        /* pilha vazia*/printf("%s", "stack underflow");
        return(-1);
    }
    else
    {
        x= pilha->dados[pilha->topo];
        pilha->topo = pilha->topo - 1;
        return x;
    }
}
