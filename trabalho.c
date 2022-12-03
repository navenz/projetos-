#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
  int dia, mes, ano;

} Data, Validade;

FILE *AbrirArq(char opcao, char caminho[30])
{
  FILE *file;
  switch (opcao)
  {
  case 'g':
    file = fopen(caminho, "wt");
    break;
  case 'l':
    file = fopen(caminho, "rt");
    break;
  case 'a':
    file = fopen(caminho, "a");
    break;
  }
  if (file == NULL)
  {
    printf("Nao foi possivel realizar a abertura do arquivo");
    exit(0);
  }
  return file;
}

void FecharArq(FILE *file)
{
  fclose(file);
}

void cabecalho(int opcaocabecalho)
{

  if (opcaocabecalho == 1)
  {
    printf("\n ====== ESTOQUE DE DESPENSA ======");
  }
  if (opcaocabecalho == 2)
  {
    printf("\n ====== LISTA DE COMPRAS ======");
  }
  if (opcaocabecalho == 3)
  {
    printf("\n ====== RELACAO FUNCIONARIOS ======");
  }
  if (opcaocabecalho == 4)
  {
    printf("\n ===== GASTOS FORNECEDORES =====");
  }
}

void menu(char arqProd[], int opcaocabecalho)
{
  int opcao, repete = 1;
  int escolha;

  do
  {
    cabecalho(opcaocabecalho);

    printf("\n 1 - Cadastrar");
    printf("\n 2 - Listar");
    printf("\n 3 - Atualizar");
    printf("\n 4 - Remover");
    printf("\n 5 - Pesquisar");

    printf("\n 6 - Sair");
    printf("\n\n Digite uma opcao.");

    scanf("%d", &escolha);
    system("cls");

    switch (escolha)
    {

    case 1:
      cadastrar(arqProd, opcaocabecalho);
      system("pause");

      break;

    case 2:
      listarArquivo(arqProd, opcaocabecalho);
      system("pause");

      break;

    case 3:

      break;

    case 4:

      break;

    case 5:

      break;

    case 6:
      printf("\n Encerrando...\n");
      system("pause");
      exit(0);

      break;

    default:
      printf("Essa opcao e invalida");
      system("pause");
    }
  } while (repete);
}

void cadastrar(char arqProd[], int opcaodecabecalho)
{
  char nome[40];
  Data p;
  int quantidade;
  Validade x;

  FILE *file;
  file = AbrirArq('a', arqProd);

  if (opcaodecabecalho == 2)
  {
    printf("Digite o nome:");
    setbuf(stdin, NULL);

    fflush(stdin);
    scanf("%40[^\n]", nome);
    getchar();

    printf("Digite a quantidade:");
    scanf("%d", &quantidade);

    fprintf(file, "%s ", nome);
    fprintf(file, "%d\n", quantidade);
  }

  if (opcaodecabecalho == 1)
  {
    printf("Digite o nome:");
    setbuf(stdin, NULL);

    fflush(stdin);
    scanf("%40[^\n]", nome);
    getchar();

    printf("Digite a quantidade:");
    scanf("%d", &quantidade);

    fprintf(file, "%s ", nome);
    fprintf(file, "%d ", quantidade);

    printf("Digite a data de entrada:");
    scanf("%d %d %d", &p.dia, &p.mes, &p.ano);

    printf("Digite a data de validade:");
    scanf("%d %d %d", &x.dia, &x.mes, &x.ano);

    fprintf(file, "%d %d %d ", x.dia, x.mes, x.ano);
    fprintf(file, "%d %d %d\n", p.dia, p.mes, p.ano);
  }

  if (opcaodecabecalho == 3)
  {
    printf("Digite o nome:");
    setbuf(stdin, NULL);

    fflush(stdin);
    scanf("%40[^\n]", nome);
    getchar();

    printf("Digite a data de entrada:");
    scanf("%d %d %d", &p.dia, &p.mes, &p.ano);

    fprintf(file, "%s ", nome);
    fprintf(file, "%d %d %d\n", p.dia, p.mes, p.ano);
  }

  if (opcaodecabecalho == 4)
  {
    printf("Digite o nome do Fornecedor:");
    setbuf(stdin, NULL);

    fflush(stdin);
    scanf("%40[^\n]", nome);
    getchar();

    printf("Digite o gasto em reais:");
    scanf("%d", &quantidade);

    printf("Digite o prazo de pagamento:");
    scanf("%d %d %d", &x.dia, &x.mes, &x.ano);

    fprintf(file, "%s ", nome);
    fprintf(file, "%d ", quantidade);
    fprintf(file, "%d %d %d\n", x.dia, x.mes, x.ano);
  }

  FecharArq(file);
}

void listarArquivo(char arqProd[], int opcaocabecalho)
{

  FILE *file;

  file = AbrirArq('l', arqProd);

  char nome[40];
  Data p;
  int quantidade;
  Validade x;

  while (!feof(file))
  {

    if (opcaocabecalho == 1)
    {

      fscanf(file, "%s", nome);
      fscanf(file, "%d", &quantidade);
      fscanf(file, "%d %d %d ", &p.dia, &p.mes, &p.ano);
      fscanf(file, "%d %d %d ", &x.dia, &x.mes, &x.ano);
      printf("Nome do produto:%s - ", nome);
      printf("Quantidade do produto: %d - ", quantidade);
      printf("Data de entrada: %d/%d/%d - ", p.dia, p.mes, p.ano);
      printf("Data de validade do produto: %d/%d/%d\n", x.dia, x.mes, x.ano);
    }

    if (opcaocabecalho == 2)
    {

      fscanf(file, "%s", nome);
      fscanf(file, "%d", &quantidade);
      printf("Nome do produto:%s - ", nome);
      printf("Quantidade do produto: %d\n", quantidade);
    }
    if (opcaocabecalho == 3)
    {

      fscanf(file, "%s", nome);
      fscanf(file, "%d %d %d ", &p.dia, &p.mes, &p.ano);
      printf("Nome:%s - ", nome);
      printf("Data de entrada: %d/%d/%d\n", p.dia, p.mes, p.ano);
    }
    if (opcaocabecalho == 4)
    {

      fscanf(file, "%s", nome);
      fscanf(file, "%d", &quantidade);
      fscanf(file, "%d %d %d ", &x.dia, &x.mes, &x.ano);

      printf("Fornecedor:%s - ", nome);
      printf("Gasto R$%d - ", quantidade);
      printf("Prazo de pagamento: %d/%d/%d\n", x.dia, x.mes, x.ano);
    }
  }

  FecharArq(file);
}

void atualizar(char arqProd[], int opcaocabecalho)
{

  FILE *file;

  file = AbrirArq('l', arqProd);
}

int main()
{

  printf("========== MENU PRINCIPAL ==========\n\n");
  printf("1 - Menu do Estoque\n");
  printf("2 - Menu da Lista de Compras\n");
  printf("3 - Menu da Relacao de Funcionarios\n");
  printf("4 - Menu de Gastos dos Fornecedores\n\n");
  printf("Digite a opcao que deseja utilizar:");

  int opcaocabecalho;
  scanf("%i", &opcaocabecalho);
  char arqEstoque[] = {"estoque.txt"};
  char arqList[] = {"lista.txt"};
  char arqFunc[] = {"func.txt"};
  char arqFor[] = {"fornec.txt"};

  if (opcaocabecalho == 1)
  {
    menu(arqEstoque, opcaocabecalho);
  }
  else if (opcaocabecalho == 2)
  {
    menu(arqList, opcaocabecalho);
  }
  else if (opcaocabecalho == 3)
  {
    menu(arqFunc, opcaocabecalho);
  }
  else if (opcaocabecalho == 4)
  {
    menu(arqFor, opcaocabecalho);
  }

  return 0;
}
