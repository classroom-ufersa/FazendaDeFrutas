#ifndef POMARES_H
#define POMARES_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Definição da estrutura para cada nó da lista encadeada de pomares */
typedef struct pomar Pomar;

/* 
   @brief Função para criar uma lista de pomares vazia.
   Retorna um ponteiro para NULL.
*/
Pomar * cria_lista_pomar(void);

/* 
   @brief Função para inserir um novo pomar na lista ordenadamente pela identificação.
   Parâmetros:
       @param lista: ponteiro para o início da lista de pomares.
       @param identificacao: identificação do pomar a ser inserido.
       @param area_plantio: área de plantio do pomar a ser inserido.
       @param arvore_presente: arvore(s) presente(s) no pomar a ser inserido.
   Retorna um ponteiro para o início da lista atualizada.
*/
Pomar * insere_pomar_lista(Pomar * lista, int identificacao, float area_plantio, char arvore_presente[]);

/* 
   @brief Função para carregar os pomares de um arquivo para a lista.
   Parâmetro:
       @param arquivo_nome: nome do arquivo contendo os dados dos pomares.
   Retorna um ponteiro para o início da lista carregada.
*/
Pomar * carrega_pomar_arquivo(char arquivo_nome[]);

/* 
   @brief para salvar os pomares da lista em um arquivo.
   Parâmetros:
       @param arquivo_nome: nome do arquivo onde os pomares serão salvos.
       @param lista: ponteiro para o início da lista de pomares a serem salvos.
*/
void insere_pomar_arquivo(char arquivo_nome[], Pomar * lista);

/* 
   @brief Função para liberar a memória alocada para a lista de pomares.
   Parâmetro:
       @param lista: ponteiro para o início da lista de pomares a ser liberada.
*/
void libera_lista_pomares(Pomar * lista);

/* 
   @brief Função para adicionar um novo pomar à lista e salvar no arquivo.
   Parâmetro:
       @param arquivo_nome: nome do arquivo onde os pomares serão salvos.
*/
Pomar * adiciona_pomar(char arquivo_nome[], Pomar * lista);

/* 
   @brief Função para imprimir os dados dos pomares na lista.
   Parâmetro:
       @param lista: ponteiro para o início da lista de pomares cujos dados serão impressos.
*/
void imprime_dados_pomar(Pomar * lista);

/* 
   @brief Função para remover um pomar da lista e atualizar o arquivo.
   Parâmetros:
       @param arquivo_nome: nome do arquivo onde os pomares são salvos.
       @param id_pomar: identificação do pomar a ser removido.
   Retorna 1 se o pomar foi removido com sucesso, 0 caso contrário.
*/
int remove_pomar(char arquivo_nome[], int id_pomar, Pomar ** lista);

void imprimirLista(Pomar *lista);

#endif
