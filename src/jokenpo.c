#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int jogador, computador;

  // inicializa o gerador de números aleatórios com base no tempo atual
  srand(time(NULL));

  printf("=== JOKENPO ===\n");
  printf("Escolha uma opcao:\n");
  printf("1 - Pedra\n");
  printf("2 - Papel\n");
  printf("3 - Tesoura\n");
  printf("Digite sua escolha: ");
  scanf("%d", &jogador);

  // computador escolhe aleatoriamente um número entre 1 e 3
  computador = rand() % 3 + 1;

  printf("\nVoce escolheu: ");
  if (jogador == 1)
    printf("Pedra\n");
  else if (jogador == 2)
    printf("Papel\n");
  else if (jogador == 3)
    printf("Tesoura\n");
  else
  {
    printf("Opcao invalida!\n");
    return 0;
  }

  printf("Computador escolheu: ");
  if (computador == 1)
    printf("Pedra\n");
  else if (computador == 2)
    printf("Papel\n");
  else if (computador == 3)
    printf("Tesoura\n");

  // decisão do vencedor
  if (jogador == computador)
  {
    printf("\nResultado: Empate!\n");
  }
  else if ((jogador == 1 && computador == 3) ||
           (jogador == 2 && computador == 1) ||
           (jogador == 3 && computador == 2))
  {
    printf("\nResultado: Voce venceu!\n");
  }
  else
  {
    printf("\nResultado: Computador venceu!\n");
  }

  return 0;
}
