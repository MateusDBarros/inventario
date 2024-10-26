#include <stdio.h>
#include <string.h>

struct  Produto
{
    char nome[25];
    char categoria[50];
    int codigo;
    int quantidade;
    float preco;
};

void adicionar(struct Produto produtos[], int *numProdutos);
void remover(struct Produto produtos[], int *numProdutos);
void ordenar(struct Produto produtos[], int *numProdutos);
void listar(struct Produto produtos[], int *numProdutos);
int procurar(struct Produto produtos[], int l, int r, char alvo[]);

int main(void)
{
    struct Produto produtos[100];
    int numProdutos = 0;
}

void adicionar(struct Produto produtos[], int *numProdutos)
{
    printf("Digite o nome do item que deseja adicionar no inventario: ");
    scanf(" %[^\n]s", produtos[*numProdutos].nome);
    printf("Digite a categoria do item: ");
    scanf(" %[^\n]s", produtos[*numProdutos].categoria);
    printf("Digite o codigo do item: ");
    scanf("%d", &produtos[*numProdutos].codigo);
    printf("Digite a quantidade do item: ");
    scanf("%d", &produtos[*numProdutos].quantidade);
    printf("Digite o valor do item: ");
    scanf("%f", &produtos[*numProdutos].preco);
    printf("\n");
    printf("Item adicionado ao inventario com sucesso!\n");
    (*numProdutos)++;
    return;
}

void remover(struct Produto produtos[], int *numProdutos)
{   
    struct Produto temp;
    char nome[25];
    printf("Entre qual item deseja remover: ");
    scanf(" %[^\n]s", nome);
    for (int i = 0; i < *numProdutos; i++)
        {
            if (strcmp(produtos[i].nome, nome) == 0)
            {
                for (int j = i; j < *numProdutos - 1; j++)
                {
                    produtos[j] = produtos[j + 1];
                }
            }
            printf("Item removido do inventario com sucesso!\n");
            (*numProdutos)--;
            return;
        }
    printf("Item nao encontrado, remocao nao concluida!\n");
}

void ordenar(struct Produto produtos[], int *numProdutos)
{

}
void listar(struct Produto produtos[], int *numProdutos)
{
    if(*numProdutos == 0) 
    {
        printf("Inventario vazio, por favor, adicione algum item!\n");
        return;
    }
    printf("| %-5d | %-20s | %-20s | %-5d | %-5f\n", "Codigo", "Nome", "Categoria", "Quantidade", "Preco");
    printf("--------------------------------------------\n");
    for (int i = 0; i < *numProdutos; i++)
    {
        printf("| %-5d | %-20s | %-20s | %-5d | %-5f\n", produtos[i].codigo, produtos[i].nome, produtos[i].categoria, produtos[i].quantidade, produtos[i].preco);
        printf("--------------------------------------------\n");
    }
}

int procurar(struct Produto produtos[], int l, int r, char alvo[])
{
    if (l > r) 
    {
        printf("Item não encontrado!\n");
        return -1;
    }
    int meio = l + (r - l) / 2;
    if (strcmp(produtos[meio].nome, alvo) == 0)
        return meio;
    if (strcmp(produtos[meio].nome, alvo) >  0)
        return procurar(produtos, l, meio - 1, alvo);
    else
        return procurar(produtos, meio + 1, r, alvo);
}

void menu(void) 
{
    do
    {
        printf("1. Adicionar item.\n");
        printf("2. Listar inventario\n");
        printf("3. Remover do inventario\n");
        printf("")
        printf
    } while (/* condition */);
    
}