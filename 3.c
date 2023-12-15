#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Produto
{
    char nome[777];
    float preco;
    int quantidade;
};
float calcularTotal(struct Produto meuProduto)
{
    return meuProduto.preco * meuProduto.quantidade;
}

void realizarCompra(struct Produto meuProduto)
{
    int quantidadeCompra;
    meuProduto.quantidade = 50;
    printf("Informe a quantidade a ser comprada: ");
    scanf("%d", &quantidadeCompra);

    if ((quantidadeCompra > 0) && (quantidadeCompra <= meuProduto.quantidade))
    {
        meuProduto.quantidade -= quantidadeCompra;
        printf("Compra realizada com sucesso!\n");
    }
    else
    {
        printf("Quantidade inválida. Verifique o estoque.\n");
    }
}

int main()
{
    struct Produto meuProduto = {"Produto A", 10.0, 50};

    int opcao;

    do
    {
        printf("\nMenu:\n");
        printf("1. Realizar uma compra\n");
        printf("2. Consultar estoque\n");
        printf("3. Sair do programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            realizarCompra(meuProduto);
            break;
        case 2:
            printf("Estoque disponivel: %d unidades\n", meuProduto.quantidade);
            printf("Valor total em estoque: R$ %.2f\n", calcularTotal(meuProduto));
            break;
        case 3:
            printf("Saindo do programa. Até mais!\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}