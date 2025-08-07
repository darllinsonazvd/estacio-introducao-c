#include <stdio.h>

int main()
{
  // Carta 1
  char estado1, codigo1[4], nome1[50];
  unsigned long int populacao1;
  float area1, pib1, densidade1, pibPerCapita1, superPoder1;
  int pontosTuristicos1;

  // Carta 2
  char estado2, codigo2[4], nome2[50];
  unsigned long int populacao2;
  float area2, pib2, densidade2, pibPerCapita2, superPoder2;
  int pontosTuristicos2;

  // Entrada Carta 1
  printf("Cadastro da Carta 1:\n");
  printf("Estado: ");
  scanf(" %c", &estado1);
  printf("Código: ");
  scanf("%s", codigo1);
  printf("Nome da Cidade: ");
  scanf(" %[^\n]", nome1);
  printf("População: ");
  scanf("%lu", &populacao1);
  printf("Área (km²): ");
  scanf("%f", &area1);
  printf("PIB (em bilhões): ");
  scanf("%f", &pib1);
  printf("Número de Pontos Turísticos: ");
  scanf("%d", &pontosTuristicos1);

  // Cálculos Carta 1
  densidade1 = (float)populacao1 / area1;
  pibPerCapita1 = (pib1 * 1000000000) / populacao1;
  superPoder1 = (float)populacao1 + area1 + (pib1 * 1000000000) + (float)pontosTuristicos1 + pibPerCapita1 + (1.0f / densidade1);

  printf("\n");

  // Entrada Carta 2
  printf("Cadastro da Carta 2:\n");
  printf("Estado: ");
  scanf(" %c", &estado2);
  printf("Código: ");
  scanf("%s", codigo2);
  printf("Nome da Cidade: ");
  scanf(" %[^\n]", nome2);
  printf("População: ");
  scanf("%lu", &populacao2);
  printf("Área (km²): ");
  scanf("%f", &area2);
  printf("PIB (em bilhões): ");
  scanf("%f", &pib2);
  printf("Número de Pontos Turísticos: ");
  scanf("%d", &pontosTuristicos2);

  // Cálculos Carta 2
  densidade2 = (float)populacao2 / area2;
  pibPerCapita2 = (pib2 * 1000000000) / populacao2;
  superPoder2 = (float)populacao2 + area2 + (pib2 * 1000000000) + (float)pontosTuristicos2 + pibPerCapita2 + (1.0f / densidade2);

  printf("\n");

  // Exibição das comparações
  printf("Comparação de Cartas:\n\n");

  printf("População: Carta 1 venceu (%d)\n", populacao1 > populacao2);
  printf("Área: Carta 1 venceu (%d)\n", area1 > area2);
  printf("PIB: Carta 1 venceu (%d)\n", pib1 > pib2);
  printf("Pontos Turísticos: Carta 1 venceu (%d)\n", pontosTuristicos1 > pontosTuristicos2);
  printf("Densidade Populacional: Carta 1 venceu (%d)\n", densidade1 < densidade2); // Menor é melhor
  printf("PIB per Capita: Carta 1 venceu (%d)\n", pibPerCapita1 > pibPerCapita2);
  printf("Super Poder: Carta 1 venceu (%d)\n", superPoder1 > superPoder2);

  return 0;
}
