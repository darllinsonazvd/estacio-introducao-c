#include <stdio.h>

// =======================
// Função recursiva da TORRE
// =======================
void moverTorre(int casas, int direcao)
{
  if (casas == 0)
    return; // Caso base da recursão: nenhuma casa restante

  if (direcao == 1)
    printf("Cima\n");
  else
    printf("Direita\n");

  moverTorre(casas - 1, direcao); // Chamada recursiva
}

// =======================
// Função recursiva da RAINHA
// =======================
void moverRainha(int casas, int etapa)
{
  if (casas == 0)
    return; // Caso base: fim da recursão

  if (etapa == 1)
    printf("Diagonal Superior Direita\n");
  else
    printf("Diagonal Inferior Esquerda\n");

  moverRainha(casas - 1, etapa); // Chamada recursiva
}

// =======================
// Função recursiva do BISPO
// =======================
void moverBispo(int casas)
{
  if (casas == 0)
    return; // Caso base da recursão

  // Loop aninhado para representar movimento diagonal
  for (int i = 0; i < 1; i++)
  { // Movimento vertical (simbolicamente 1 casa por vez)
    for (int j = 0; j < 1; j++)
    { // Movimento horizontal
      printf("Diagonal Direita Cima\n");
    }
  }

  moverBispo(casas - 1); // Recursão: próxima casa
}

// =======================
// Função do CAVALO
// =======================
void moverCavalo()
{
  int movimentoVertical = 2;   // duas casas para cima
  int movimentoHorizontal = 1; // uma casa para a direita

  printf("\nMovimentos do Cavalo:\n");

  // Loop externo controla movimento vertical
  for (int i = 0; i < movimentoVertical; i++)
  {
    printf("Cima\n");

    // Loop interno com múltiplas condições
    int j = 0;
    while (j < movimentoHorizontal)
    {
      if (i == 1 && j == 0)
      {
        // No último movimento vertical, faz o movimento lateral
        printf("Direita\n");
        break; // Sai do loop interno
      }
      j++;

      if (i == 0)
        continue; // Ignora o movimento lateral até o fim do movimento vertical
    }
  }
}

// =======================
// Função principal
// =======================
int main()
{
  int casasTorre = 3;
  int casasBispo = 2;
  int casasRainha = 4;

  printf("=== Movimentos da Torre ===\n");
  moverTorre(casasTorre, 1); // Torre se move para cima
  moverTorre(casasTorre, 2); // Torre se move para a direita

  printf("\n=== Movimentos do Bispo ===\n");
  moverBispo(casasBispo);

  printf("\n=== Movimentos da Rainha ===\n");
  moverRainha(casasRainha, 1);
  moverRainha(casasRainha, 2);

  printf("\n=== Movimentos do Cavalo ===\n");
  moverCavalo();

  return 0;
}
