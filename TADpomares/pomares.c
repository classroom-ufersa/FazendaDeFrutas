#include "pomares.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct pomar{
    int identificacao;
    float area_plantio;
    char arvore_presente[100];
    Pomar * prox_elemento;
    int total_arvores;
}Pomar;

Pomar * cria_lista_pomar(void) {
    return NULL;
}

Pomar * insere_pomar_lista(Pomar * lista, int identificacao, float area_plantio, char arvore_presente[], int total_arvores) {
    Pomar * novo_elemento = (Pomar*) malloc(sizeof(Pomar));
    if(novo_elemento == NULL) {
        printf("Falha ao alocacar a memoria.\n");
        exit(1);
    }
    novo_elemento->identificacao = identificacao;
    novo_elemento->area_plantio = area_plantio;
    strcpy(novo_elemento->arvore_presente, arvore_presente);
    novo_elemento->total_arvores = total_arvores;

    if(lista == NULL || identificacao < lista->identificacao) {
        novo_elemento->prox_elemento = lista;
        return novo_elemento;
    }

    Pomar * elemento_atual = lista;
    while(elemento_atual->prox_elemento != NULL && identificacao > elemento_atual->prox_elemento->identificacao) {
        elemento_atual = elemento_atual->prox_elemento;
    }
    novo_elemento->prox_elemento = elemento_atual->prox_elemento;
    elemento_atual->prox_elemento = novo_elemento;

    return lista;
}

Pomar * carrega_pomar_arquivo(char arquivo_nome[]){
    Pomar * lista = cria_lista_pomar();
    FILE * arquivo = fopen(arquivo_nome, "r");
    if(arquivo == NULL){
        printf("Erro ao abrir arquivo.\n");
        exit(1);
    }
    int identificacao;
    float area_plantio;
    char arvore_presente[100];
    int total_arvores;

    while(fscanf(arquivo, "%d %f %[^\n] %d", &identificacao, &area_plantio, &arvore_presente, &total_arvores) == 4) {
        lista = insere_pomar_lista(lista, identificacao, area_plantio, arvore_presente, total_arvores);
    }

    fclose(arquivo);
    return lista;
}

void insere_pomar_arquivo(char arquivo_nome[], Pomar * lista){
   FILE * arquivo = fopen(arquivo_nome, "w"); 
   if(arquivo == NULL) {
        printf("Erro ao abrir arquivo.\n");
        exit(1);
    }
    while(lista != NULL) {
        fprintf(arquivo, "%d\t%f\t%s\t%s\n", lista->identificacao, lista->area_plantio, lista->arvore_presente, lista->total_arvores);
        lista = lista->prox_elemento;
    }

    fclose(arquivo);
}

void libera_lista_pomares(Pomar * lista) {
    Pomar * elemento_atual;

    while(lista != NULL) {
        elemento_atual = lista;
        lista = lista->prox_elemento;
        free(elemento_atual);
    }
}

void adiciona_pomar(char arquivo_nome[]){
    Pomar * lista = carrega_pomar_arquivo(arquivo_nome);
    int identificacao;
    float area_plantio;
    char arvore_presente[50];
    int total_arvores;

    printf("==== ADICIONAR POMAR ====\n");
    printf("Informe a identificacao do pomar: \n");
    scanf("%d", &identificacao);
    printf("Informe a area de plantio: \n");
    scanf("%f", &area_plantio);
    printf("Informe as arvores que estao no pomar: \n");
    scanf(" %[^\n]", arvore_presente);
    printf("Informe o total de arvores que estao no pomar:\n");
    scanf("%d", &total_arvores);
    printf("=========================\n");

    lista = insere_pomar_lista(lista, identificacao, area_plantio, arvore_presente, total_arvores);
    insere_pomar_arquivo (arquivo_nome, lista);
    libera_lista_pomares(lista);

    printf("Adicao realizada com sucesso.\n");
}

void imprime_dados_pomar(Pomar * lista) {
    printf("========== POMARES ==========\n");
    if(lista == NULL) {
        printf("O pomar nao foi encontrado.\n");
    }
    while(lista != NULL) {
        printf("Identificacao: %d\n", lista->identificacao);
        printf("Area de Plantio: %f\n", lista->area_plantio);
        printf("Arvores Presentes: %s\n", lista->arvore_presente);
        printf("Total de Arvores: %d\n", lista->total_arvores);
        if(lista->prox_elemento != NULL) {
            printf("\n");
        }
        lista = lista->prox_elemento;
    }
    printf("===============================\n");
}

int remove_pomar(char arquivo_nome[], int id_pomar) {
    Pomar * lista = carrega_pomar_arquivo(arquivo_nome);
    Pomar * elemento_atual = lista;
    Pomar * elemento_remover;
    int removido = 0;

    if(lista != NULL) {
        if(lista->identificacao == id_pomar) {
            elemento_remover = lista;
            lista = lista->prox_elemento;
            free(elemento_remover);
            removido = 1;
        } else {
            while(elemento_atual->prox_elemento != NULL) {
                if(elemento_atual->prox_elemento->identificacao == id_pomar) {
                    elemento_remover = elemento_atual->prox_elemento;
                    elemento_atual->prox_elemento = elemento_remover->prox_elemento;
                    free(elemento_remover);
                    removido = 1;
                    break;
                }
                elemento_atual = elemento_atual->prox_elemento;
            }
        }
        insere_pomar_arquivo(arquivo_nome, lista);
        libera_lista_pomares(lista);
    }
    return removido;
}
