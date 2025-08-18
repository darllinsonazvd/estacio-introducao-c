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

// Função auxiliar para comparar atributos numéricos (maior vence, exceto densidade)
int compararNumerico(float valor1, float valor2, int menorVence)
{
  if (valor1 == valor2)
    return 0;
  if (menorVence)
    return (valor1 < valor2) ? 1 : 2;
  else
    return (valor1 > valor2) ? 1 : 2;
}

// Função para exibir o menu
void exibirMenu()
{
  printf("\n=== Escolha um atributo para comparar ===\n");
  printf("1 - Estado\n");
  printf("2 - Codigo\n");
  printf("3 - Nome da cidade\n");
  printf("4 - Populacao\n");
  printf("5 - Area\n");
  printf("6 - PIB\n");
  printf("7 - Pontos turisticos\n");
  printf("8 - Densidade populacional\n");
  printf("9 - PIB per capita\n");
  printf("Opcao: ");
}

// Função para processar a escolha
int processarEscolha(int opcao, Carta c1, Carta c2)
{
  int vencedor = 0;
  switch (opcao)
  {
  case 1: // Estado
    vencedor = (strcmp(c1.estado, c2.estado) == 0) ? 0 : -1;
    printf("Estado 1: %s | Estado 2: %s\n", c1.estado, c2.estado);
    break;

  case 2: // Código
    vencedor = (strcmp(c1.codigo, c2.codigo) == 0) ? 0 : -1;
    printf("Codigo 1: %s | Codigo 2: %s\n", c1.codigo, c2.codigo);
    break;

  case 3: // Nome da cidade
    vencedor = (strcmp(c1.nome, c2.nome) == 0) ? 0 : -1;
    printf("Cidade 1: %s | Cidade 2: %s\n", c1.nome, c2.nome);
    break;

  case 4: // População
    vencedor = compararNumerico(c1.populacao, c2.populacao, 0);
    printf("Populacao 1: %d | Populacao 2: %d\n", c1.populacao, c2.populacao);
    break;

  case 5: // Área
    vencedor = compararNumerico(c1.area, c2.area, 0);
    printf("Area 1: %.2f | Area 2: %.2f\n", c1.area, c2.area);
    break;

  case 6: // PIB
    vencedor = compararNumerico(c1.pib, c2.pib, 0);
    printf("PIB 1: %.2f | PIB 2: %.2f\n", c1.pib, c2.pib);
    break;

  case 7: // Pontos turísticos
    vencedor = compararNumerico(c1.pontosTuristicos, c2.pontosTuristicos, 0);
    printf("Pontos Turisticos 1: %d | Pontos Turisticos 2: %d\n", c1.pontosTuristicos, c2.pontosTuristicos);
    break;

  case 8: // Densidade populacional (menor vence)
    vencedor = compararNumerico(c1.densidadePopulacional, c2.densidadePopulacional, 1);
    printf("Densidade 1: %.2f | Densidade 2: %.2f\n", c1.densidadePopulacional, c2.densidadePopulacional);
    break;

  case 9: // PIB per capita
    vencedor = compararNumerico(c1.pibPerCapita, c2.pibPerCapita, 0);
    printf("PIB per Capita 1: %.2f | PIB per Capita 2: %.2f\n", c1.pibPerCapita, c2.pibPerCapita);
    break;

  default:
    printf("Opcao invalida!\n");
    vencedor = -1;
  }

  return vencedor;
}

int main()
{
  Carta carta1, carta2;
  int opcao1, opcao2;

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

  carta2.densidadePopulacional = carta2.populacao / carta2.area;
  carta2.pibPerCapita = carta2.pib / carta2.populacao;

  // Escolha de 2 atributos
  exibirMenu();
  scanf("%d", &opcao1);

  exibirMenu();
  scanf("%d", &opcao2);

  printf("\n=== Resultado da Comparacao ===\n");

  int vencedor1 = processarEscolha(opcao1, carta1, carta2);
  int vencedor2 = processarEscolha(opcao2, carta1, carta2);

  // Decisão final (melhor de 2 atributos)
  if (vencedor1 == vencedor2 && vencedor1 != 0 && vencedor1 != -1)
    printf("\nCarta %d venceu considerando os dois atributos!\n", vencedor1);
  else if (vencedor1 != vencedor2 && vencedor1 > 0 && vencedor2 > 0)
    printf("\nEmpate tecnico! Cada carta venceu em um atributo.\n");
  else if (vencedor1 == 0 || vencedor2 == 0)
    printf("\nEmpate em um dos atributos!\n");
  else
    printf("\nNao foi possivel determinar um vencedor claro.\n");

  return 0;
}
