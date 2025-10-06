#include <stdio.h>

#define TAM 10 // Tamanho do tabuleiro (10x10)
#define H 5    // Tamanho das matrizes de habilidades (5x5)

// -------------------------------------------------------
// Função: inicializarTabuleiro
// Objetivo: Preencher toda a matriz do tabuleiro com 0 (representa água).
// -------------------------------------------------------
void inicializarTabuleiro(int tabuleiro[TAM][TAM])
{
  for (int i = 0; i < TAM; i++)
    for (int j = 0; j < TAM; j++)
      tabuleiro[i][j] = 0; // 0 = água
}

// -------------------------------------------------------
// Função: exibirTabuleiro
// Objetivo: Mostrar o conteúdo do tabuleiro no console.
// -------------------------------------------------------
void exibirTabuleiro(int tabuleiro[TAM][TAM])
{
  for (int i = 0; i < TAM; i++)
  {
    for (int j = 0; j < TAM; j++)
      printf("%d ", tabuleiro[i][j]); // Exibe cada célula separada por espaço
    printf("\n");
  }
  printf("\n");
}

// -------------------------------------------------------
// Função: posicionarNavios
// Objetivo: Posicionar 4 navios no tabuleiro:
//           - 2 navios em posições horizontais/verticais
//           - 2 navios em posições diagonais
// Representação: 3 = navio
// -------------------------------------------------------
void posicionarNavios(int tabuleiro[TAM][TAM])
{
  // Navio horizontal (linha fixa, colunas variando)
  for (int j = 2; j < 5; j++)
    tabuleiro[1][j] = 3;

  // Navio vertical (coluna fixa, linhas variando)
  for (int i = 5; i < 8; i++)
    tabuleiro[i][7] = 3;

  // Navio diagonal principal (↘)
  for (int i = 0; i < 3; i++)
    tabuleiro[3 + i][3 + i] = 3;

  // Navio diagonal secundária (↙)
  for (int i = 0; i < 3; i++)
    tabuleiro[8 - i][i + 1] = 3;
}

// -------------------------------------------------------
// Função: gerarCone
// Objetivo: Criar uma matriz em formato de cone (1 = área afetada).
// O cone é representado como um triângulo apontando para baixo.
// -------------------------------------------------------
void gerarCone(int cone[H][H])
{
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < H; j++)
    {
      // À medida que descemos as linhas, o cone se alarga
      cone[i][j] = (j >= H / 2 - i && j <= H / 2 + i) ? 1 : 0;
    }
  }
}

// -------------------------------------------------------
// Função: gerarCruz
// Objetivo: Criar uma matriz em formato de cruz (1 = área afetada).
// A cruz é formada pela linha e coluna central da matriz.
// -------------------------------------------------------
void gerarCruz(int cruz[H][H])
{
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < H; j++)
    {
      // Marca o centro vertical e horizontal
      cruz[i][j] = (i == H / 2 || j == H / 2) ? 1 : 0;
    }
  }
}

// -------------------------------------------------------
// Função: gerarOctaedro
// Objetivo: Criar uma matriz com formato de octaedro (ou losango).
// A área afetada é definida pela soma das distâncias ao centro.
// -------------------------------------------------------
void gerarOctaedro(int oct[H][H])
{
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < H; j++)
    {
      // Fórmula da distância de Manhattan para formar o losango
      oct[i][j] = (abs(i - H / 2) + abs(j - H / 2) <= H / 2) ? 1 : 0;
    }
  }
}

// -------------------------------------------------------
// Função: aplicarHabilidade
// Objetivo: Sobrepor uma habilidade (cone, cruz ou octaedro)
//           no tabuleiro principal, com base em um ponto de origem.
//           5 = área afetada por habilidade.
// -------------------------------------------------------
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[H][H], int linhaOrigem, int colunaOrigem)
{
  int offset = H / 2; // Quantos elementos antes e depois do centro

  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < H; j++)
    {
      // Calcula a posição no tabuleiro com base no centro da habilidade
      int linha = linhaOrigem - offset + i;
      int coluna = colunaOrigem - offset + j;

      // Verifica se está dentro dos limites do tabuleiro
      if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM)
      {
        // Aplica o efeito apenas se a célula da habilidade for 1
        if (habilidade[i][j] == 1 && tabuleiro[linha][coluna] == 0)
          tabuleiro[linha][coluna] = 5; // Marca área afetada
      }
    }
  }
}

// -------------------------------------------------------
// Função principal
// -------------------------------------------------------
int main()
{
  int tabuleiro[TAM][TAM];
  int cone[H][H], cruz[H][H], octaedro[H][H];

  // Inicializa o tabuleiro com água
  inicializarTabuleiro(tabuleiro);

  // Posiciona os navios
  posicionarNavios(tabuleiro);

  // Gera as três habilidades
  gerarCone(cone);
  gerarCruz(cruz);
  gerarOctaedro(octaedro);

  // Aplica as habilidades em diferentes pontos do tabuleiro
  aplicarHabilidade(tabuleiro, cone, 2, 2);     // Cone no canto superior esquerdo
  aplicarHabilidade(tabuleiro, cruz, 5, 5);     // Cruz no centro
  aplicarHabilidade(tabuleiro, octaedro, 7, 8); // Octaedro no canto inferior direito

  // Exibe o resultado final
  exibirTabuleiro(tabuleiro);

  return 0;
}
