#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tam 2
#define tamA 5

struct Aluno
{
    char nome[777], datadenascimento[777];
    float media, nota[tam];
};
// Calculando media

void calculandomedia(struct Aluno *aluno)
{
    int i, j;
    float somanota = 0;
    for (i = 0; i < tamA; i++)
    {
        printf("Aluno %i\n", i + 1);
        for (j = 0; j < tam; j++)
        {
            somanota += aluno[i].nota[j];
        }

        aluno[i].media = somanota / tam;
        printf("Media: %f\n", aluno[i].media);
        somanota = 0;
    }
}

void verificar(struct Aluno *aluno)
{
    int i;
    for (i = 0; i < tamA; i++)
    {
        if (aluno[i].media >= 7)
        {
            printf("Aluno %i\n", i + 1);
            printf("Aluno aprovado!!\n");
        }
        else
        {
            printf("Aluno %i\n", i + 1);
            printf("Aluno reprovado!!\n");
        }
    }
    return;
}

int main()
{
    struct Aluno aluno[tamA];
    int i, j;

    for (i = 0; i < tamA; i++)
    {
        printf("Aluno %i\n", i + 1);
        printf("Nome: ");
        gets(aluno[i].nome);
        printf("Data De Nascimento: ");
        gets(aluno[i].datadenascimento);
        for (j = 0; j < tam; j++)
        {
            printf("Nota %i: ", j + 1);
            scanf("%f", &aluno[i].nota[j]);
        }
        fflush(stdin);
    }
    calculandomedia(aluno);
    verificar(aluno);

    return 0;
}