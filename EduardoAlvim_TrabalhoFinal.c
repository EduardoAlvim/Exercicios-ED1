#include <stdio.h>
#include <stdlib.h>

typedef struct Data
{
    int dia, mes, ano;
} data;

typedef struct Endereco
{
    char rua[30],cidade[30],estado[30];
    int numero;
} endereco;

typedef struct Cliente
{
    char cpf[30],nome[30],telefone[30];
    endereco ende;
    data dataNascimento;
} cliente;

typedef struct Produto
{
    char descricao[30];
    int codigo, quantEstoque;
    float precoUnitario;
} produto;

typedef struct Venda{
  cliente.cpf cpf[30];
  produto.codigo cod;
  int codVenda, quantComprada;
}venda;

void main()
{
    printf("Hello world!\n");
}
