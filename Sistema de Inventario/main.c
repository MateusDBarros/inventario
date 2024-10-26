#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    int escolha;
    char alvo[25];
    do
    {
        printf("\n");
        printf("---Sistema de Inventario---\n");
        printf("1. Adicionar Item.\n");
        printf("2. Listar Inventario\n");
        printf("3. Remover do Inventario\n");
        printf("4. Buscar Item\n");
        printf("5. Sair\n");
        scanf("%d", &escolha);

        switch(escolha)
        {
            case 1:
                system("cls");
                adicionar(produtos, &numProdutos);
            break;
            case 2:
                system("cls");
                ordenar(produtos, &numProdutos);
                listar(produtos, &numProdutos);
            break;
            case 3:
                system("cls");
                remover(produtos, &numProdutos);
            break;
            case 4:
            system("cls");
                if(numProdutos == 0) 
                {
                    printf("Inventario vazio, por favor, adicione algum item!\n");
                }
                else {
                    printf("Qual item deseja procurar? ");
                    scanf(" %[^\n]s", alvo);
                    int index = procurar(produtos, 0, numProdutos, alvo);
                    if(index != -1)
                    {
                        printf("| %-5s | %-20s | %-20s | %-5s | %-5s\n", "Codigo", "Nome", "Categoria", "Quantidade", "Preco");
                        printf("------------------------------------------------------------------------\n");
                        printf("| %-5d | %-20s | %-20s | %-5d | %-5f\n", produtos[index].codigo, produtos[index].nome, produtos[index].categoria, produtos[index].quantidade, produtos[index].preco);
                        
                    }
                }
                
            break;
            case 5:
                printf("Encerrando o programa...");
                return 0;
            break;

            default:
                printf("Opcao Invalida!\n");
            break;
        }

    } while (5 != escolha);
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
    if(*numProdutos == 0) 
    {
        printf("Inventario vazio, por favor, adicione algum item!\n");
        return;
    }
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
    struct Produto temp;
    for (int i = 0; i < *numProdutos - 1; i++)
    {
        for (int j = 0; j < *numProdutos - 1 - i; j++)
        {
            if(strcmp(produtos[j].nome, produtos[j + 1].nome) > 0) {
                temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }
}
void listar(struct Produto produtos[], int *numProdutos)
{
    if(*numProdutos == 0) 
    {
        printf("Inventario vazio, por favor, adicione algum item!\n");
        return;
    }
    printf("| %-5s | %-20s | %-20s | %-5s | %-5s\n", "Codigo", "Nome", "Categoria", "Quantidade", "Preco");
    printf("-----------------------------------------------------------------------------\n");
    for (int i = 0; i < *numProdutos; i++)
    {
        printf("| %-5d  | %-20s | %-20s | %-5d | %-.2f\n", produtos[i].codigo, produtos[i].nome, produtos[i].categoria, produtos[i].quantidade, produtos[i].preco);
        printf("-----------------------------------------------------------------------------\n");
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
