#include "arvore.h"

struct arvores {
    char nome [30];
    char tipo [20];
    int quantidade_frutas;
    int idade_arvore;
};

void Arvores *adicionar_arvores(int id, Arvores * arvores) {
    char * nome = (char*)malloc(30 * sizeof(char));
    char * tipo = (char*)malloc(20 * sizeof(char));

    if (nome == NULL && tipo == NULL){
        printf("Erro de alocacao, memoria insuficiente");
        exit(1);
    }
}

int Arvores *remover_arvores() {

    return 0;
}

int Arvores *alterar_quantidade_frutas() {

    return 0;
}

int Arvores *listar_arvores() {

    return 0;
}