#include "pomares.h"

typedef struct pomar{
    int identificacao;
    float area_plantio;
    char arvore_presente[100];
    Pomar * prox_elemento;
}Pomar;

Pomar * cria_lista_pomar(void) {
    return NULL;
}

Pomar * insere_pomar_lista(Pomar * lista, int identificacao, float area_plantio, char arvore_presente[]) {
    Pomar * novo_elemento = (Pomar*) malloc(sizeof(Pomar));
    if(novo_elemento == NULL) {
        printf("Falha ao alocacar a memoria.\n");
        exit(1);
    }
    novo_elemento->identificacao = identificacao;
    novo_elemento->area_plantio = area_plantio;
    strcpy(novo_elemento->arvore_presente, arvore_presente);

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

    while(fscanf(arquivo, "%d %f %[^\n]%*c", &identificacao, &area_plantio, &arvore_presente) == 3 ) {
        lista = insere_pomar_lista(lista, identificacao, area_plantio, arvore_presente);
    }

    fclose(arquivo);
    return lista;
}

void insere_pomar_arquivo(char arquivo_nome[], Pomar * lista){
   FILE * arquivo = fopen(arquivo_nome, "wt"); 
   if(arquivo == NULL) {
        printf("Erro ao abrir arquivo.\n");
        exit(1);
    }
    if (lista == NULL) {
        printf("lista vazia");
    }
    while(lista != NULL) {
        fprintf(arquivo, "%d\t%f\t%s\n", lista->identificacao, lista->area_plantio, lista->arvore_presente);
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

void imprimirLista(Pomar *lista) {
    Pomar *temp = lista;
    while (temp != NULL) {
        printf("%d ", temp->identificacao);
        temp = temp->prox_elemento;
    }
    printf("\n");
}

Pomar * adiciona_pomar(char arquivo_nome[], Pomar * lista){
    int identificacao;
    float area_plantio;
    char arvore_presente[100];

    printf("==== ADICIONAR POMAR ====\n");
    printf("Informe a identificacao do pomar: \n");
    while (1) {
        if (scanf("%d", &identificacao) == 1) {
            while(getchar() != '\n');
            break;
        } else {
            printf("O ID inserido e invalido, insira apenas numeros:\n");
            while (getchar() != '\n'); 
        }
    }
    printf("Informe a area de plantio: \n");
    while (1) {
        if (scanf("%f", &area_plantio) == 1) {
            while(getchar() != '\n');
            break;
        } else {
            printf("A area inserida e invalida, insira apenas numeros:\n");
            while (getchar() != '\n'); 
        }
    }
    printf("Informe as arvores que estao no pomar: \n");
    scanf(" %[^\n]", arvore_presente);
    printf("=========================\n");

    lista = insere_pomar_lista(lista, identificacao, area_plantio, arvore_presente);
    insere_pomar_arquivo (arquivo_nome, lista);
    printf("Adicao realizada com sucesso.\n");
    return lista;
}

void imprime_dados_pomar(Pomar * lista) {
    printf("========== POMARES ==========\n");
    if(lista == NULL) {
        printf("O pomar nao foi encontrado.\n");
    }
    while(lista != NULL) {
        printf("Identificacao: %d\n", lista->identificacao);
        printf("Area de Plantio: %.2f\n", lista->area_plantio);
        printf("Arvores Presentes: %s\n", lista->arvore_presente);
        if(lista->prox_elemento != NULL) {
            printf("\n");
        }
        lista = lista->prox_elemento;
    }
    printf("===============================\n");
}

int remove_pomar(char arquivo_nome[], int id_pomar, Pomar ** lista) {
    Pomar *atual = *lista;
    Pomar *anterior = NULL;
    
    while (atual != NULL && atual->identificacao != id_pomar) {
        anterior = atual;
        atual = atual->prox_elemento;
    }

    if (atual == NULL) {
        return 0;
    }

    if (anterior == NULL) {
        *lista = atual->prox_elemento;
    } else {
        anterior->prox_elemento = atual->prox_elemento;
    }

    free(atual);
    insere_pomar_arquivo(arquivo_nome, *lista);
    return 1;
}
