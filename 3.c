#include <stdio.h>
#include <string.h>
#include <locale.h>

struct Produto
{
    char nome[777];
    float preco;
    int quantidadeEstoque;
};

float calcularValorTotal(struct Produto produto)
{
    return produto.preco * produto.quantidadeEstoque;
}

void realizarCompra(struct Produto *produto)
{
    int quantidadeCompra;

    printf("Digite a quantidade a ser comprada: ");
    scanf("%d", &quantidadeCompra);

    if (quantidadeCompra > 0 && quantidadeCompra <= produto->quantidadeEstoque)
    {
        produto->quantidadeEstoque -= quantidadeCompra;
        printf("Compra realizada com sucesso. Novo estoque: %d\n", produto->quantidadeEstoque);
    }
    else
    {
        printf("Quantidade invalida. Compra nao realizada.\n");
    }
}

void Estoque(struct Produto produto)
{
    printf("Nome do produto: %s\n", produto.nome);
    printf("Quantidade em estoque: %d\n", produto.quantidadeEstoque);
    printf("Preco por unidade: R$ %.2f\n", produto.preco);
    printf("Valor total em estoque: R$ %.2f\n", calcularValorTotal(produto));
}

void adicionarProduto(struct Produto *produto)
{
    printf("Digite o nome do produto: ");
    scanf("%s", produto->nome);
    printf("Digite a quantidade em estoque: ");
    scanf("%d", &produto->quantidadeEstoque);
    printf("Digite o preco por unidade: ");
    scanf("%f", &produto->preco);
}

int main()
{
    setlocale(LC_ALL, "");
    struct Produto meuProduto;

    int escolha;

    do
    {
        printf("\n===== Menu =====\n");
        printf("1. Adicionar produto\n");
        printf("2. Realizar uma compra\n");
        printf("3. Consultar estoque\n");
        printf("4. Sair do programa\n");

        printf("Escolha uma opcao: \n");
        scanf("%i", &escolha);
        fflush(stdin);
        switch (escolha)
        {
        case 1:
            adicionarProduto(&meuProduto);
            break;

        case 2:
            realizarCompra(&meuProduto);
            break;

        case 3:
            Estoque(meuProduto);
            break;

        case 4:
            printf("Saindo do programa.\n");
            break;

        default:
            printf("Opcaoo invalida. Tente novamente.\n");
        }

    } while (escolha != 4);

    return 0;
}
