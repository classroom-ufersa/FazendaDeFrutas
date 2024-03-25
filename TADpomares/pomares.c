#include "pomares.h"
#include "TADarvore/arvore.h"

void adicionar_pomar(Pomar pomares[], int *total_pomares) {
    if (*total_pomares >= MAX_POMARES) {
        printf("Limite de pomares atingido.\n");
        return;
    }

    Pomar novo_pomar;

    printf("Digite a identificacao do pomar: ");
    scanf("%d", &novo_pomar.identificacao);

    printf("Digite a area de plantio do pomar: ");
    scanf("%f", &novo_pomar.area_plantio);

    novo_pomar.total_arvores = 0;

    pomares[*total_pomares] = novo_pomar;
    (*total_pomares)++;

    printf("Pomar adicionado com sucesso.\n");

    FILE *arquivo = fopen("listapomares.txt", "a");
    fprintf(arquivo, "\n%d\t%f\t%d\t%d\n%p\n", &novo_pomar.identificacao, &novo_pomar.area_plantio, &novo_pomar.total_arvores, &novo_pomar.arvores);
}

void remover_pomar(Pomar pomares[], int *total_pomares) {
    if (*total_pomares == 0) {
        printf("Nenhum pomar para remover.\n");
        return;
    }

    int identificacao_pomar;
    printf("Digite a identificacao do pomar que deseja remover: ");
    scanf("%d", &identificacao_pomar);

    int i, encontrado = 0;
    for (i = 0; i < *total_pomares; i++) {
        if (pomares[i].identificacao == identificacao_pomar) {
            encontrado = 1;
            break;
        }
    }

    if (encontrado) {
        for (int j = i; j < *total_pomares - 1; j++) {
            pomares[j] = pomares[j + 1];
        }
        (*total_pomares)--;
        printf("Pomar removido com sucesso.\n");
    } else {
        printf("Pomar nao encontrado.\n");
    }
}

void listar_pomares_e_arvores(Pomar pomares[], int total_pomares) {
    if (total_pomares == 0) {
        printf("Nenhum pomar cadastrado.\n");
        return;
    }

    printf("Lista de Pomares e suas Arvores:\n");
    for (int i = 0; i < total_pomares; i++) {
        printf("Pomar %d - Identificacao: %d, Area de plantio: %.2f\n", i + 1, pomares[i].identificacao, pomares[i].area_plantio);
        printf("Arvores:\n");
        for (int j = 0; j < pomares[i].total_arvores; j++) {
            printf("Nome: %s, Tipo: %s, Quantidade de Frutas: %d, Idade: %d anos\n", pomares[i].arvores[j].nome, pomares[i].arvores[j].tipo, pomares[i].arvores[j].quantidade_frutas, pomares[i].arvores[j].idade);
        }
        printf("\n");
    }
}