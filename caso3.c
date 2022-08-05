#include <stdio.h>
#include <stdlib.h>

typedef struct arv
{
    int info;
    struct arv *esq;
    struct arv *dir;
} arvore;
arvore *raiz;

arvore* insere(arvore *root, arvore *r, int dado)
{
    if(r==NULL)
    {
        r = (arvore *) malloc(sizeof(arvore));
        if(r==NULL)
            printf("\nMemoria Insufuciente !!!");
        else
        {
            r->esq=NULL;
            r->dir=NULL;
            r->info=dado;
            if(root==NULL)
                return r;
            if(r->info <= root->info)
                root->esq = r;
            else
                root->dir = r;
            return r;
        }
    }
    if(dado < r->info)
        insere(r,r->esq,dado);
    else
        insere(r,r->dir,dado);
    return r;
}

void PreOrdem(arvore *root)
{
    if(root==NULL)
        return;
    printf("\n%d",root->info);
    PreOrdem(root->esq);
    PreOrdem(root->dir);
}

void EmOrdem(arvore *root)
{
    if(root==NULL)
        return;
    EmOrdem(root->esq);
    printf("\n%d",root->info);
    EmOrdem(root->dir);
}

void PosOrdem(arvore *root)
{
    if(root==NULL)
        return;
    PosOrdem(root->esq);
    PosOrdem(root->dir);
    printf("\n%d",root->info);
}

arvore *remove(arvore *root, int key)
{
    arvore *p,*p2;
    if(root==NULL)
        return root;
    if(root->info==key)
    {
        if(root->esq==root->dir)
        {
            free(root);
            return NULL;
        }
        else if(root->esq==NULL)
        {
            p = root->dir;
            free(root);
            return p;
        }
        else if(root->dir==NULL)
        {
            p = root->esq;
            free(root);
            return p;
        }
        else{
            printf("\n3 caso");
        }
        }
    if(root->info < key)
        root->dir = remove(root->dir,key);
    else
        root->esq = remove(root->esq,key);
    return root;
}

void main()
{
    int valor, opcao;
    raiz=NULL;
    while(opcao != 0)
    {
        printf("\nMenu \n1 Inserir \n2 Pre-Ordem \n3 Em-Ordem \n4 Pos-Ordem \n0 Sair\n");
        scanf("%d",&opcao);
        if(opcao == 1)
        {
            printf("\nDigite o valor que quer colocar: ");
            scanf("%d",&valor);

            if(raiz==NULL)
                raiz=insere(raiz,raiz,valor);
            else
                insere(raiz,raiz,valor);

        }
        else if(opcao ==2)
        {
            printf("\n\nPre-Ordem : ");
            PreOrdem(raiz);
        }
        else if(opcao ==3)
        {
            printf("\n\nEm-Ordem : ");
            EmOrdem(raiz);
        }
        else if(opcao ==4)
        {
            printf("\n\nPos-Ordem : ");
            PosOrdem(raiz);
        }
    }
}
