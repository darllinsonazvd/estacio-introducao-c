#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados da carta
typedef struct
{
  char estado[50];
  char codigo[10];
  char nome[50];
  int populacao;
  float area;
  float pib;
  int pontosTuristicos;
  float densidadePopulacional;
  float pibPerCapita;
} Carta;

int main()
{
  Carta carta1, carta2;
  int opcao;

  // Cadastro da primeira carta
  printf("=== Cadastro da Carta 1 ===\n");
  printf("Estado: ");
  scanf("%s", carta1.estado);
  printf("Codigo: ");
  scanf("%s", carta1.codigo);
  printf("Nome da cidade: ");
  scanf("%s", carta1.nome);
  printf("Populacao: ");
  scanf("%d", &carta1.populacao);
  printf("Area: ");
  scanf("%f", &carta1.area);
  printf("PIB: ");
  scanf("%f", &carta1.pib);
  printf("Pontos turisticos: ");
  scanf("%d", &carta1.pontosTuristicos);

  // Calcula atributos derivados
  carta1.densidadePopulacional = carta1.populacao / carta1.area;
  carta1.pibPerCapita = carta1.pib / carta1.populacao;

  // Cadastro da segunda carta
  printf("\n=== Cadastro da Carta 2 ===\n");
  printf("Estado: ");
  scanf("%s", carta2.estado);
  printf("Codigo: ");
  scanf("%s", carta2.codigo);
  printf("Nome da cidade: ");
  scanf("%s", carta2.nome);
  printf("Populacao: ");
  scanf("%d", &carta2.populacao);
  printf("Area: ");
  scanf("%f", &carta2.area);
  printf("PIB: ");
  scanf("%f", &carta2.pib);
  printf("Pontos turisticos: ");
  scanf("%d", &carta2.pontosTuristicos);

  // Calcula atributos derivados
  carta2.densidadePopulacional = carta2.populacao / carta2.area;
  carta2.pibPerCapita = carta2.pib / carta2.populacao;

  // Menu de escolha
  printf("\n=== Escolha o atributo para comparar ===\n");
  printf("1 - Estado (string)\n");
  printf("2 - Codigo (string)\n");
  printf("3 - Nome da cidade (string)\n");
  printf("4 - Populacao (int)\n");
  printf("5 - Area (float)\n");
  printf("6 - PIB (float)\n");
  printf("7 - Pontos turisticos (int)\n");
  printf("8 - Densidade populacional (float)\n");
  printf("9 - PIB per capita (float)\n");
  printf("Opcao: ");
  scanf("%d", &opcao);

  printf("\n=== Resultado da Comparacao ===\n");

  switch (opcao)
  {
  case 1: // Estado
    if (strcmp(carta1.estado, carta2.estado) == 0)
      printf("Empate! Ambos estados sao iguais (%s)\n", carta1.estado);
    else
      printf("Nao ha criterio numerico para decidir. Estado 1: %s | Estado 2: %s\n", carta1.estado, carta2.estado);
    break;

  case 2: // Codigo
    if (strcmp(carta1.codigo, carta2.codigo) == 0)
      printf("Empate! Ambos codigos sao iguais (%s)\n", carta1.codigo);
    else
      printf("Nao ha criterio numerico para decidir. Codigo 1: %s | Codigo 2: %s\n", carta1.codigo, carta2.codigo);
    break;

  case 3: // Nome da cidade
    if (strcmp(carta1.nome, carta2.nome) == 0)
      printf("Empate! Ambas cidades sao iguais (%s)\n", carta1.nome);
    else
      printf("Nao ha criterio numerico para decidir. Cidade 1: %s | Cidade 2: %s\n", carta1.nome, carta2.nome);
    break;

  case 4: // População
    if (carta1.populacao > carta2.populacao)
      printf("Carta 1 venceu! (%d vs %d)\n", carta1.populacao, carta2.populacao);
    else if (carta2.populacao > carta1.populacao)
      printf("Carta 2 venceu! (%d vs %d)\n", carta2.populacao, carta1.populacao);
    else
      printf("Empate! (%d vs %d)\n", carta1.populacao, carta2.populacao);
    break;

  case 5: // Área
    if (carta1.area > carta2.area)
      printf("Carta 1 venceu! (%.2f vs %.2f)\n", carta1.area, carta2.area);
    else if (carta2.area > carta1.area)
      printf("Carta 2 venceu! (%.2f vs %.2f)\n", carta2.area, carta1.area);
    else
      printf("Empate! (%.2f vs %.2f)\n", carta1.area, carta2.area);
    break;

  case 6: // PIB
    if (carta1.pib > carta2.pib)
      printf("Carta 1 venceu! (%.2f vs %.2f)\n", carta1.pib, carta2.pib);
    else if (carta2.pib > carta1.pib)
      printf("Carta 2 venceu! (%.2f vs %.2f)\n", carta2.pib, carta1.pib);
    else
      printf("Empate! (%.2f vs %.2f)\n", carta1.pib, carta2.pib);
    break;

  case 7: // Pontos turísticos
    if (carta1.pontosTuristicos > carta2.pontosTuristicos)
      printf("Carta 1 venceu! (%d vs %d)\n", carta1.pontosTuristicos, carta2.pontosTuristicos);
    else if (carta2.pontosTuristicos > carta1.pontosTuristicos)
      printf("Carta 2 venceu! (%d vs %d)\n", carta2.pontosTuristicos, carta1.pontosTuristicos);
    else
      printf("Empate! (%d vs %d)\n", carta1.pontosTuristicos, carta2.pontosTuristicos);
    break;

  case 8: // Densidade populacional (menor vence)
    if (carta1.densidadePopulacional < carta2.densidadePopulacional)
      printf("Carta 1 venceu! (%.2f vs %.2f)\n", carta1.densidadePopulacional, carta2.densidadePopulacional);
    else if (carta2.densidadePopulacional < carta1.densidadePopulacional)
      printf("Carta 2 venceu! (%.2f vs %.2f)\n", carta2.densidadePopulacional, carta1.densidadePopulacional);
    else
      printf("Empate! (%.2f vs %.2f)\n", carta1.densidadePopulacional, carta2.densidadePopulacional);
    break;

  case 9: // PIB per capita
    if (carta1.pibPerCapita > carta2.pibPerCapita)
      printf("Carta 1 venceu! (%.2f vs %.2f)\n", carta1.pibPerCapita, carta2.pibPerCapita);
    else if (carta2.pibPerCapita > carta1.pibPerCapita)
      printf("Carta 2 venceu! (%.2f vs %.2f)\n", carta2.pibPerCapita, carta1.pibPerCapita);
    else
      printf("Empate! (%.2f vs %.2f)\n", carta1.pibPerCapita, carta2.pibPerCapita);
    break;

  default:
    printf("Opcao invalida!\n");
    break;
  }

  return 0;
}
