#include "sorvete.h"
#include <stdio.h>

void menu() {
  printf("=========== Escolha uma opcao ===========\n");
  printf("1 - Adicionar Sorvete no fim\n");
  printf("2 - Adicionar Sorvete no inicio\n");
  printf("3 - Listar Sorvetes\n");
  printf("4 - Buscar Sorvete\n");
  printf("0 - Sair\n");
  printf("==========================================\n");
}

int main() {
  Lista *lista = criarLista();
  int opcao;
  menu();
  scanf("%d", &opcao);
  while (opcao != 0) {
    if (opcao == 1) {
      Sorvete *sorvete = lerSorvete();
      adicionaFim(lista, sorvete);
    }
    if (opcao == 2) {
      Sorvete *sorvete = lerSorvete();
      adicionaInicio(lista, sorvete);
    }
    if (opcao == 3) {
      mostrarSorvetes(lista);
    }
    if (opcao == 4) {
      imprimirSorvetes(lista);
    }
    menu();
    scanf("%d", &opcao);
  }
  return 0;
}
