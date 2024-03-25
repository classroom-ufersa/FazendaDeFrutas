#ifndef POMARES_H
#define POMARES_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../TADarvore/arvore.h"

#define MAX_POMARES 100

typedef struct {
    int identificacao;
    float area_plantio;
    Arvore arvores[100];
    int total_arvores;
} Pomar;

void adicionar_pomar(Pomar pomares[], int *total_pomares);
void remover_pomar(Pomar pomares[], int *total_pomares);
void listar_pomares_e_arvores(Pomar pomares[], int total_pomares);

#endif