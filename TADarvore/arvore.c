#include "arvore.h"

void adicionar_arvore(Arvore arvores[], int *total_arvores) {
    if (*total_arvores >= MAX_ARVORES) {
        printf("Limite de arvores atingido.\n");
        return;
    }

    Arvore nova_arvore;

    printf("Digite o nome da arvore: ");
    scanf("%s", &nova_arvore.nome);

    printf("Digite o tipo da arvore: ");
    scanf("%s", &nova_arvore.tipo);

    printf("Digite a quantidade de frutas da arvore: ");
    scanf("%d", &nova_arvore.quantidade_frutas);

    printf("Digite a idade da arvore: ");
    scanf("%d", &nova_arvore.idade);

    arvores[*total_arvores] = nova_arvore;
    (*total_arvores)++;

    printf("Arvore adicionada com sucesso.\n");
}

void remover_arvore(Arvore arvores[], int *total_arvores) {
    if (*total_arvores == 0) {
        printf("Nenhuma arvore para remover.\n");
        return;
    }

    char nome_arvore[50];
    printf("Digite o nome da arvore que deseja remover: ");
    scanf("%s", nome_arvore);

    int i, encontrado = 0;
    for (i = 0; i < *total_arvores; i++) {
        if (strcmp(arvores[i].nome, nome_arvore) == 0) {
            encontrado = 1;
            break;
        }
    }

    if (encontrado) {
        for (int j = i; j < *total_arvores - 1; j++) {
            arvores[j] = arvores[j + 1];
        }
        (*total_arvores)--;
        printf("Arvore removida com sucesso.\n");
    } else {
        printf("Arvore nao encontrada.\n");
    }
}

void mudar_quantidade_frutas(Arvore arvores[], int total_arvores) {
    char nome_arvore[50];
    printf("Digite o nome da arvore para mudar a quantidade de frutas: ");
    scanf("%s", nome_arvore);

    int i;
    for (i = 0; i < total_arvores; i++) {
        if (strcmp(arvores[i].nome, nome_arvore) == 0) {
            printf("Digite a nova quantidade de frutas: ");
            scanf("%d", &arvores[i].quantidade_frutas);
            printf("Quantidade de frutas alterada com sucesso.\n");
            return;
        }
    }

    printf("Arvore nao encontrada.\n");
}

void buscar_arvore_por_nome(Arvore arvores[], int total_arvores) {
    char nome_arvore[50];
    printf("Digite o nome da arvore que deseja buscar: ");
    scanf("%s", nome_arvore);

    int i;
    for (i = 0; i < total_arvores; i++) {
        if (strcmp(arvores[i].nome, nome_arvore) == 0) {
            printf("Arvore encontrada:\n");
            printf("Nome: %s\n", arvores[i].nome);
            printf("Tipo: %s\n", arvores[i].tipo);
            printf("Quantidade de frutas: %d\n", arvores[i].quantidade_frutas);
            printf("Idade: %d anos\n", arvores[i].idade);
            return;
        }
    }

    printf("Arvore nao encontrada.\n");
}