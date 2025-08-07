#include <stdio.h>

int main()
{
  // Declaração das variáveis para as 3 notas e a média
  float nota1, nota2, nota3, media;

  // Entrada de dados
  printf("Digite a primeira nota: ");
  scanf("%f", &nota1);

  printf("Digite a segunda nota: ");
  scanf("%f", &nota2);

  printf("Digite a terceira nota: ");
  scanf("%f", &nota3);

  // Cálculo da média
  media = (nota1 + nota2 + nota3) / 3;

  // Saída do resultado
  printf("A média das notas é: %.2f\n", media);

  return 0;
}
