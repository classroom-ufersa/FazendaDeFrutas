#include <ctype.h>
#include <stdio.h>
#include "TADarvore\arvore.h"
#include "TADpomares\pomares.h"

void mostrar_menu(void) {
    printf(
        "======= MENU =======\n"
        "[1] - Adicionar pomar\n"
        "[2] - Remover pomar\n"
        "[3] - Adicionar arvore\n"
        "[4] - Remover arvore\n"
        "[5] - Mudar quantidade de frutas de uma arvore\n"
        "[6] - Buscar arvore por nome\n"
        "[7] - Listar pomares e suas arvores\n"
        "[8] - Sair\n"
        "====================\n"
    );
}

int trataEntrada(const char *entrada) {
    if (*entrada == '\0') {
        return -1;
    }
    int numero = 0;
    while (*entrada != '\0' && *entrada != '\n') {
        if (!isdigit(*entrada)) {
            return -1;
        }
        numero = numero * 10 + (*entrada - '0');
        entrada++;
    }
    return numero;
}

int main(void) {
    char entrada[50];
    char arquivo_pomares[] = "TADpomares/pomar.txt";
    char arquivo_arvores[] = "TADarvore/arvore.txt";
    char nome_arvore[40];
    int identificacao_pomar;
    Arvores * lista_arvores;
    Arvores * resultado_busca;
    Pomar * lista_pomares = carrega_pomar_arquivo(arquivo_pomares);
    int opcao = 0;

    while(opcao != 8){
        mostrar_menu();
        printf("Escolha uma opcao do menu: ");
        scanf(" %[^\n]", entrada);
        opcao = trataEntrada(entrada);
        switch(opcao) {
            case 1:
                lista_pomares = adiciona_pomar(arquivo_pomares, lista_pomares);
                break;
            case 2:
                printf("Informe a identificacao do pomar que sera removido:\n");
                scanf("%d", &identificacao_pomar);
                if(remove_pomar(arquivo_pomares, identificacao_pomar, &lista_pomares) == 1) {
                    printf("Pomar removido com sucesso!\n");
                } else {
                    printf("O Pomar nao foi encontrado. Tente novamente.\n");
                }
                break;
            case 3:
                adiciona_arvore(arquivo_arvores);
                break;
            case 4:
                printf("Informe o nome da arvore que sera removida:\n");
                scanf(" %[^\n]", nome_arvore);
                if(remove_arvore(arquivo_arvores, nome_arvore) == 1) {
                    printf("Arvore removida com sucesso!\n");
                } else {
                    printf("A Arvore nao foi encontrada. Tente novamente. *\n");
                }
                break;
            case 5:
                printf("Informe o nome da arvore para mudar a quantidade de frutas:\n");
                scanf(" %[^\t]", nome_arvore);
                mudar_quantidade_frutas_arvore(arquivo_arvores, nome_arvore);
                break;
            case 6:
                printf("Informe o nome da arvore para realizar a busca:\n");
                scanf(" %[^\t]", nome_arvore);
                lista_arvores = carrega_arvore_arquivo(arquivo_arvores);
                resultado_busca = busca_arvore(lista_arvores, nome_arvore);
                if(resultado_busca != NULL) {
                    printf("==== BUSCADOR DE ARVORE ====\n");
                    imprime_dados_arvore(resultado_busca);
                    printf("============================\n");
                } else {
                    printf("A Arvore nao foi encontrada. Tente novamente.\n");
                }
                libera_lista_arvore(lista_arvores);
                break;
            case 7:
                imprime_dados_pomar(lista_pomares);
                break;
            case 8:
                printf("O Programa de gerenciamento da fazenda de frutas foi encerrado, Obrigado.\n");
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    }
    return 0;
}
