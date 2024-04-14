#ifndef ARVORE_H
#define ARVORE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Definição da estrutura para cada nó da lista encadeada de árvores */
typedef struct arvores Arvores;

/* 
   @brief Função para criar uma lista de árvores vazia.
   Retorna um ponteiro para NULL.
*/
Arvores * cria_lista_arvore(void);

/* 
   @brief Função para inserir uma nova árvore na lista ordenadamente pelo nome.
   Parâmetros:
       @param lista: ponteiro para o início da lista de árvores.
       @param nome: nome da árvore a ser inserida.
       @param tipo: tipo da árvore a ser inserida.
       @param quantidade_frutas: quantidade de frutas da árvore a ser inserida.
       @param idade: idade da árvore a ser inserida.
   Retorna um ponteiro para o início da lista atualizada.
*/
Arvores * insere_arvore_lista(Arvores * lista, char nome[], char tipo[], int quantidade_frutas, int idade);

/* 
   @brief Função para incrementar a quantidade de frutas de uma árvore existente na lista.
   Parâmetros:
       @param lista: ponteiro para o início da lista de árvores.
       @param quantidade_frutas: quantidade a ser incrementada na árvore.
   Retorna um ponteiro para o início da lista atualizada.
*/
Arvores * insere_quantidade_frutas_arvore_lista(Arvores * lista, int quantidade_frutas);

/* 
   @brief Função para carregar as árvores de um arquivo para a lista.
   Parâmetro:
       @param nome_arquivo: nome do arquivo contendo os dados das árvores.
   Retorna um ponteiro para o início da lista carregada.
*/
Arvores * carrega_arvore_arquivo(char nome_arquivo[]);

/* 
   @brief Função para salvar as árvores da lista em um arquivo.
   Parâmetros:
       @param nome_arquivo: nome do arquivo onde as árvores serão salvas.
       @param lista: ponteiro para o início da lista de árvores a serem salvas.
*/
void insere_arvore_arquivo(char nome_arquivo[], Arvores * lista);

/* 
   @brief Função para liberar a memória alocada para a lista de árvores.
   Parâmetro:
       @param lista: ponteiro para o início da lista de árvores a ser liberada.
*/
void libera_lista_arvore(Arvores * lista);

/* 
   @brief Função para adicionar uma nova árvore à lista e salvar no arquivo.
   Parâmetro:
       @param nome_arquivo: nome do arquivo onde as árvores serão salvas.
*/
void adiciona_arvore(char nome_arquivo[]);

/* 
   @brief Função para imprimir os dados de uma árvore.
   Parâmetro:
       @param dados: ponteiro para a árvore cujos dados serão impressos.
*/
void imprime_dados_arvore(Arvores * dados);

/* 
   @brief Função para buscar uma árvore na lista pelo nome.
   Parâmetros:
       @param lista: ponteiro para o início da lista de árvores.
       @param nome_arvore: nome da árvore a ser buscada.
   Retorna um ponteiro para a árvore encontrada ou NULL se não encontrada.
*/
Arvores * busca_arvore(Arvores * lista, char nome_arvore[]);

/* 
   @brief Função para remover uma árvore da lista e atualizar o arquivo.
   Parâmetros:
       @param nome_arquivo: nome do arquivo onde as árvores são salvas.
       @param nome_arvore: nome da árvore a ser removida.
   Retorna 1 se a árvore foi removida com sucesso, 0 caso contrário.
*/
int remove_arvore(char nome_arquivo[], char nome_arvore[]);

/* 
   @brief Função para alterar a quantidade de frutas de uma árvore na lista e atualizar o arquivo.
   Parâmetros:
       @param nome_arquivo: nome do arquivo onde as árvores são salvas.
       @param nome_arvore: nome da árvore cuja quantidade de frutas será alterada.
*/
void mudar_quantidade_frutas_arvore(char nome_arquivo[], char nome_arvore[]);

#endif 