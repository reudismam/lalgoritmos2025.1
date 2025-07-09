#include "sorvete.h"
#include <stdio.h>
#include <stdlib.h>

struct sorvete {
  int cod;
  char sabor[20];
  float preco;
};

struct no {
  Sorvete dado;
  struct no *prox;
};

struct lista {
  No *inicio;
};

void adicionaFim(Lista *lista, Sorvete *dado) {
  No *novo = (No *)malloc(sizeof(No));
  novo->dado = *dado;
  novo->prox = NULL;
  if (lista->inicio == NULL) {
    lista->inicio = novo;
  } else {
    No *pi;
    for (pi = lista->inicio; pi->prox != NULL; pi = pi->prox)
      ;
    pi->prox = novo;
  }
}

void adicionaInicio(Lista *lista, Sorvete *dado) {
  No *novo = (No *)malloc(sizeof(No));
  novo->dado = *dado;
  novo->prox = lista->inicio;
  lista->inicio = novo;
}

No *busca(Lista *lista, int cod) {
  No *pi;
  for (pi = lista->inicio; pi != NULL && pi->dado.cod != cod; pi = pi->prox)
    ;
  return pi;
}

void mostrarSorvetes(Lista *lista) {
  No *pi;
  for (pi = lista->inicio; pi != NULL; pi = pi->prox) {
    printf("Codigo: %d\n", pi->dado.cod);
    printf("Sabor: %s\n", pi->dado.sabor);
    printf("Preco: %.2f\n", pi->dado.preco);
  }
}

Sorvete *lerSorvete() {
  Sorvete *sorvete = (Sorvete *)malloc(sizeof(Sorvete));
  printf("Digite o codigo, o sabor e o preco do sorvete: \n");
  scanf("%d %s %f", &sorvete->cod, sorvete->sabor, &sorvete->preco);
  return sorvete;
}

Lista *criarLista() {
  Lista *lista = (Lista *)malloc(sizeof(Lista));
  lista->inicio = NULL;
  return lista;
}

void imprimirSorvetes(Lista *lista) {
  int cod;
  printf("Digite o codigo do sorvete: \n");
  scanf("%d", &cod);
  No *no = busca(lista, cod);
  if (no != NULL) {
    printf("Codigo: %d %s %f\n", no->dado.cod, no->dado.sabor,
           no->dado.preco);
  } else {
    printf("Sorvete nao encontrado\n");
  }
}
