#include <stdio.h>
#include <stdlib.h>

/*Faça uma função que receba a idade de uma pessoa expressa em anos,  meses e dias e retorne a função principal o valor expresso apenas em dias.
Defina que todos os meses têm 30 dias. */

int idade(int a, int m, int d);

void main()
{
    int anos, meses, dias, resp;
    printf("\nDigite sua idade expressa em anos, meses e dias respectivamente:");
    scanf("%d %d %d",&anos,&meses,&dias);
    resp = idade(anos, meses, dias);
    printf("\nSua idade expressa em dias e: %d",resp);
}

int idade(int a, int m, int d)
{
    int r;
    r=d;
    r=r+(m*30);
    r=r+(a*360);
    return r;
}
