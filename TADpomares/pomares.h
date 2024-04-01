#ifndef POMARES_H
#define POMARES_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*  Chama a TADarvore   */
#include "C:\Users\Usuário\Desktop\Est. 1\FazendaDeFrutas\TADarvore\arvore.h"
//#include "TADarvore\arvore.h"

/*  Define tamanho máximo do pomar  */
#define MAX_POMARES 100

typedef struct {
    int identificacao;
    float area_plantio;
    int total_arvores;
    Arvore arvores[100];
    //Arvore *arvores;
    //Pomar *prox;
} Pomar;

/*
@brief Adiciona novos pomares

@param pomares Uma variável do tipo Pomar que armazena os dados dos pomares
@param total pomares Um ponteiro do tipo inteiro que armazena o total de árvores
*/
void adicionar_pomar(Pomar pomares[], int *total_pomares);

/*
brief remove um pomar existente

@param
@param
*/
void remover_pomar(Pomar pomares[], int *total_pomares);

void listar_pomares_e_arvores(Pomar pomares[], int total_pomares);

#endif
