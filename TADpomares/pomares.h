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
Pomares *adicionar_pomares(Pomares * pomares, int * numero_pomares);

/*
@brief Esta função remove pomares

@param
*/
Pomares *remover_pomares();

/*
@brief Esta função lista os pomares e suas árvores

@param
*/
Pomares *listar_pomares();
