#include <stdio.h>

int main()
{
  int idade, matricula;
  float altura;
  char nome[50];

  printf("Digite sua idade:\n");
  scanf("%d", &idade);

  printf("Digite sua altura:\n");
  scanf("%f", &altura);

  printf("Digite seu nome:\n");
  scanf("%s", nome);

  printf("Digite sua matrícula:\n");
  scanf("%d", &matricula);

  printf("\nNome: %s\n", nome);
  printf("Idade: %d\n", idade);
  printf("Altura: %.2f\n", altura);
  printf("Matrícula: %d\n", matricula);
  return 0;
}