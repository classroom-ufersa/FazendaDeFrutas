#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "arvore.h"

/*Definição de novo tipo: Pomares*/
typedef struct pomares Pomares;

/*
@brief Esta função adiciona pomares

@param
*/
void Pomares *adicionar_pomares(Pomares * pomares, int * numero_pomares);

/*
@brief Esta função remove pomares

@param
*/
int Pomares *remover_pomares();

/*
@brief Esta função lista os pomares e suas árvores

@param
*/
int Pomares *listar_pomares();