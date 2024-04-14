#include "arvore.h"

struct arvores {
    char nome[50];
    char tipo[50];
    int quantidade_frutas;
    int idade;
    Arvores * prox_elemento;
};

Arvores * cria_lista_arvore(void) {
    return NULL;
}

Arvores * insere_arvore_lista(Arvores * lista, char nome[], char tipo[], int quantidade_frutas, int idade) {
    Arvores *novo_elemento = (Arvores*) malloc(sizeof(Arvores));
    if(novo_elemento == NULL) {
        printf("Falha ao alocar memoria para um novo elemento.\n");
        exit(1);
    }
    strcpy(novo_elemento->nome, nome);
    strcpy(novo_elemento->tipo, tipo);
    novo_elemento->quantidade_frutas = quantidade_frutas;
    novo_elemento->idade = idade;

    if(lista == NULL || strcmp(novo_elemento->nome, lista->nome) <= 0) {
        novo_elemento->prox_elemento = lista;
        return novo_elemento;
    }

    Arvores * elemento_atual = lista;
    while(elemento_atual->prox_elemento != NULL && strcmp(novo_elemento->nome, elemento_atual->prox_elemento->nome) > 0) {
        elemento_atual = elemento_atual->prox_elemento;
    }
    novo_elemento->prox_elemento = elemento_atual->prox_elemento;
    elemento_atual->prox_elemento = novo_elemento;

    return lista;
}

Arvores * insere_quantidade_frutas_arvore_lista(Arvores * lista, int quantidade_frutas) {
    Arvores * elemento_atual = lista;
    while(elemento_atual->prox_elemento != NULL) {
        elemento_atual = elemento_atual->prox_elemento;
    }
    elemento_atual->quantidade_frutas += quantidade_frutas;
    return lista;
}

Arvores * carrega_arvore_arquivo(char nome_arquivo[]) {
    Arvores * lista = cria_lista_arvore();
    FILE * arquivo = fopen(nome_arquivo, "r");
    if(arquivo == NULL) {
        printf("Falha ao abrir o arquivo '%s'.\n", nome_arquivo);
        exit(1);
    }
    char nome[50];
    char tipo[50];
    int quantidade_frutas;
    int idade;

    while(fscanf(arquivo, " %[^\t] %[^\t] %d %d", nome, tipo, &quantidade_frutas, &idade) == 4) {
        lista = insere_arvore_lista(lista, nome, tipo, quantidade_frutas, idade);
    }

    fclose(arquivo);
    return lista;
}

void insere_arvore_arquivo(char nome_arquivo[], Arvores * lista) {
    FILE * arquivo = fopen(nome_arquivo, "w");
    if(arquivo == NULL) {
        printf("Falha ao abrir o arquivo '%s'.\n", nome_arquivo);
        exit(1);
    }
    while(lista != NULL) {
        fprintf(arquivo, "%s\t%s\t%d\t%d\n", lista->nome, lista->tipo, lista->quantidade_frutas, lista->idade);
        lista = lista->prox_elemento;
    }

    fclose(arquivo);
}

void libera_lista_arvore(Arvores * lista) {
    Arvores * elemento_atual;

    while(lista != NULL) {
        elemento_atual = lista;
        lista = lista->prox_elemento;
        free(elemento_atual);
    }
}

void adiciona_arvore(char nome_arquivo[]) {
    Arvores * lista = carrega_arvore_arquivo(nome_arquivo);
    char nome[50];
    char tipo[50];
    int quantidade_frutas;
    int idade;

    printf("==== ADICIONAR ARVORE ====\n");
    printf("Informe o nome da arvore:\n");
    scanf(" %[^\n]", nome);
    printf("Informe o tipo da arvore(citrica, de caroco, etc):\n");
    scanf(" %[^\n]", tipo);
    printf("Informe a quantidade de frutas da arvore:\n");
    scanf("%d", &quantidade_frutas);
    printf("Informe a idade da arvore:\n");
    scanf("%d", &idade);
    printf("==========================\n");

    lista = insere_arvore_lista(lista, nome, tipo, quantidade_frutas, idade);
    insere_arvore_arquivo(nome_arquivo, lista);
    libera_lista_arvore(lista);
    
    printf("Adicao realizada com sucesso.\n");
}

void imprime_dados_arvore(Arvores * dados) {
    printf("Nome: %s\n", dados->nome);
    printf("Tipo(citrica, de caroco, etc): %s\n", dados->tipo);
    printf("Quantidade de frutas: %d\n", dados->quantidade_frutas);
    printf("Idade da arvore: %d\n", dados->idade);
}

Arvores * busca_arvore(Arvores * lista, char nome_arvore[]) {
    while (lista != NULL) {
        if (strcmp(lista->nome, nome_arvore) == 0) {
            return lista;
        }
        lista = lista->prox_elemento;
    }
    return NULL;
}

int remove_arvore(char arquivo_nome[], char nome_arvore[]) {
    Arvores * lista = carrega_arvore_arquivo(arquivo_nome);
    Arvores * elemento_atual = lista;
    Arvores * elemento_anterior = NULL;
    int removido = 0;

    while(elemento_atual != NULL) {
        if(strcmp(elemento_atual->nome, nome_arvore) == 0) {
            if(elemento_anterior == NULL) {
                lista = elemento_atual->prox_elemento;
            } else {
                elemento_anterior->prox_elemento = elemento_atual->prox_elemento;
            }
            free(elemento_atual);
            removido = 1;
            break;
        }
        elemento_anterior = elemento_atual;
        elemento_atual = elemento_atual->prox_elemento;
    }

    if(removido) {
        insere_arvore_arquivo(arquivo_nome, lista);
        libera_lista_arvore(lista);
    } else {
        libera_lista_arvore(lista);
    }
    return removido;
}

void mudar_quantidade_frutas_arvore(char nome_arquivo[], char nome_arvore[]) {
    Arvores * lista = carrega_arvore_arquivo(nome_arquivo);
    Arvores * resultado_busca = busca_arvore(lista, nome_arvore);
    int nova_quantidade_frutas;

    if(resultado_busca != NULL) {
        printf("============ INFORMACOES DA ARVORE ============\n");
        imprime_dados_arvore(resultado_busca);
        printf("=================================================\n");

        printf(" === Alterar a quantidade de frutas da arvore === \n");
        printf("Informe a nova quantidade de frutas: ");
        scanf("%d", &nova_quantidade_frutas);
        resultado_busca->quantidade_frutas = nova_quantidade_frutas;
        insere_arvore_arquivo(nome_arquivo, lista);
        
        printf("Quantidade de frutas alterada com sucesso!\n");
    } else {
        printf("A arvore nao foi encontrada. Tente novamente.\n");
    }
        libera_lista_arvore(lista);
}