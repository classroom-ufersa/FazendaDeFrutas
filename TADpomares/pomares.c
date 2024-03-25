#include "pomares.h"

// Estrutura Pomares
typedef struct pomares {
    int id;
    float area;
    Arvores *arvores;
}Pomares;

void adicionar_pomares(Pomares *pomares, int *numero_pomares) {
    (*numero_pomares++);
    pomares = realloc(pomares, (*numero_pomares) * sizeof(Pomares));

    if (pomares == NULL){
        printf("Erro de alocacao, memoria insuficiente.\n");
        exit(1);
    }
    
    pomares[*numero_pomares - 1].id = *numero_pomares;

    printf("Informe a area do novo pomar: ");
    scanf("%f", &pomares[*numero_pomares - 1].area);
    //Lógica do arvores
}
/*
int Pomares *remover_pomares() {

    return 0;
}

int Pomares *listar_pomares() {

    return 0;
}
*/