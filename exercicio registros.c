#include <stdio.h>
#include <stdlib.h>

/* Faça um algoritmo que receba os dados de 10 pessoas. Nome, endereço (rua, número, bairro),data de nascimento (dia, mês e ano) e salário.
Mostre a média dos salários, mostre onome das pessoas que possuem saláriomaior que R$ 2.000,00.Mostre quantas pessoas tem o saláriomenor que R$ 1.000,00. */

struct Endereco{
    char rua[100];
    int numero;
    char bairro[100];
};

struct Data{
    int dia,mes,ano;
};

typedef struct
{
    char nome[100];
    float salario;
    struct Endereco endereco;
    struct Data data;
} Pessoa;

void main()
{
    Pessoa pessoa[10];
    float mediasal;
    int acmsal=0, cont=0;

    for(int i = 0 ; i <10; i++){
        printf("\nDigite seu nome: ");
        fflush(stdin);
        gets(pessoa[i].nome);
        printf("\nDigite seu salario: ");
        scanf("%f",&pessoa[i].salario);
        acmsal = acmsal + pessoa[i].salario;
        if(pessoa[i].salario <1000){
            cont++;
        }
        printf("\nDigite sua rua: ");
        fflush(stdin);
        gets(pessoa[i].endereco.rua);
        printf("\nDigite seu bairro: ");
        fflush(stdin);
        gets(pessoa[i].endereco.bairro);
        printf("\nDigite o numero: ");
        scanf("%d",&pessoa[i].endereco.numero);
        printf("\nDigite sua data de nascimento (dia/mes/ano): ");
        scanf("%d/%d/%d",&pessoa[i].data.dia,&pessoa[i].data.mes,&pessoa[i].data.ano);
    }
    mediasal = (float)acmsal / 10;
    printf("\nMedia dos salarios: %.2f",mediasal);
    printf("\nPessoas com salario maior que 2.000: ");
    for(int i=0;i<10;i++){
        if(pessoa[i].salario >2000){
            printf("\n %s",pessoa[i].nome);
        }
    }
    printf("\nQuantidade de pessoas com salario menor de que 1.000: %d",cont);
}
