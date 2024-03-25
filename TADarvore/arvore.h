#ifndef ARVORE_H
#define ARVORE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ARVORES 100

typedef struct {
    char nome[50];
    char tipo[50];
    int quantidade_frutas;
    int idade;
} Arvore;

void adicionar_arvore(Arvore arvores[], int *total_arvores);
void remover_arvore(Arvore arvores[], int *total_arvores);
void mudar_quantidade_frutas(Arvore arvores[], int total_arvores);
void buscar_arvore_por_nome(Arvore arvores[], int total_arvores);

#endif