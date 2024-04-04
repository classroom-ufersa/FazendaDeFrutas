#ifndef ARVORE_H
#define ARVORE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct arvores Arvores;

Arvores * cria_lista_arvore(void);

Arvores * insere_arvore_lista(Arvores * lista, char nome[], char tipo[], int quantidade_frutas, int idade);

Arvores * carrega_arvore_arquivo(char nome_arquivo[]);

void insere_arvore_arquivo(char nome_arquivo[], Arvores * lista);

void libera_lista_arvore(Arvores * lista);

void adiciona_arvore(char nome_arquivo[]);

void imprime_dados_arvore(Arvores * dados);

Arvores * busca_arvore(Arvores * lista, char nome_arvore[]);

int remove_arvore(char nome_arquivo[], char nome_arvore[]);

void mudar_quantidade_frutas_arvore(char nome_arquivo[], char nome_arvore[]);

#endif