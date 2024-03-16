#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[50];
    int matricula;
    char curso[50];
    char data_nascimento[11];
} Aluno;

void adicionarAluno(Aluno alunos[], int *numAlunos)
{
    printf("Digite o nome do aluno: ");
    scanf(" %[^\n]s", alunos[*numAlunos].nome);
    printf("Digite a matricula do aluno: ");
    scanf("%d", &alunos[*numAlunos].matricula);
    printf("Digite o curso do aluno: ");
    scanf(" %[^\n]s", alunos[*numAlunos].curso);
    printf("Digite a data de nascimento do aluno: ");
    scanf(" %[^\n]s", alunos[*numAlunos].data_nascimento);
    (*numAlunos)++;
    printf("Aluno adicionado com sucesso! \n");
}

void buscarAlunoPorNome(Aluno alunos[], int numAlunos, char nome[])
{
    int encontrado = 0;
    for (int i = 0; i < numAlunos; i++)
    {
        if (strcmp(alunos[i].nome, nome) == 0)
        {
            printf("Nome: %s\n", alunos[i].nome);
            printf("Matricula: %d\n", alunos[i].matricula);
            printf("Curso: %s\n", alunos[i].curso);
            printf("Data de Nascimento: %s\n", alunos[i].data_nascimento);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado)
    {
        printf("Aluno nao encontrado.\n");
    }
}

void excluirAluno(Aluno alunos[], int *numAlunos, char nome[])
{
    int encontrado = 0;
    for (int i = 0; i < *numAlunos; i++)
    {
        if (strcmp(alunos[i].nome, nome) == 0)
        {
            for (int j = i; j < *numAlunos - 1; j++)
            {
                alunos[j] = alunos[j + 1];
            }
            (*numAlunos)--;
            encontrado = 1;
            printf("Exclusão do aluno feita com sucesso!\n");
            break;
        }
    }
    if (!encontrado)
    {
        printf("Aluno não encontrado. \n");
    }
}

void listarAlunos(Aluno alunos[], int numAlunos)
{
    if (numAlunos == 0)
    {
        printf("Nenhum aluno cadastrado:\n");
    }
    else
    {
        printf("Lista de Alunos:\n");
        for (int i = 0; i < numAlunos; i++)
        {
            printf("Nome: %s\n", alunos[i].nome);
            printf("Matricula: %d\n", alunos[i].matricula);
            printf("Curso: %s\n", alunos[i].curso);
            printf("Data de nascimento: %s\n", alunos[i].data_nascimento);
            printf("\n");
        }
    }
}

int main()
{
    Aluno alunos[100];
    int numAlunos = 0;
    int opcao;
    char nome[50];

    do
    {
        printf("\nMenu:\n");
        printf("1. Adicionar novo aluno\n");
        printf("2. Buscar aluno por nome\n");
        printf("3. Excluir aluno\n");
        printf("4. Listar todos os alunos\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            adicionarAluno(alunos, &numAlunos);
            break;
        case 2:
            printf("Digite o nome do aluno: ");
            scanf(" %[^\n]s", nome);
            buscarAlunoPorNome(alunos, numAlunos, nome);
            break;
        case 3:
            printf("Digite o nome do aluno a ser excluido: ");
            scanf(" %[^\n]s", nome);
            excluirAluno(alunos, &numAlunos, nome);
            break;
        case 4:
            listarAlunos(alunos, numAlunos);
            break;
        case 5:
            printf("Saindo do programa...\n");
            break;
        default:
            printf("Opcao invalida.\n");
        }
    } while (opcao != 5);

    return 0;
}
