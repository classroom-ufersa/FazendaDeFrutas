#include "../TADpomares/pomares.h"

int main() {
    Pomar pomares[100];
    int total_pomares = 0;
    int opcao;
    
    do {
        printf("\nMenu:\n");
        printf("1. Adicionar pomar\n");
        printf("2. Remover pomar\n");
        printf("3. Adicionar arvore\n");
        printf("4. Remover arvore\n");
        printf("5. Mudar quantidade de frutas de uma arvore\n");
        printf("6. Buscar arvore por nome\n");
        printf("7. Listar pomares e suas arvores\n");
        printf("8. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionar_pomar(pomares, &total_pomares);
                break;
            case 2:
                remover_pomar(pomares, &total_pomares);
                break;
            case 3:
                adicionar_arvore(pomares[total_pomares - 1].arvores, &pomares[total_pomares - 1].total_arvores);
                break;
            case 4:
                remover_arvore(pomares[total_pomares - 1].arvores, &pomares[total_pomares - 1].total_arvores);
                break;
            case 5:
                mudar_quantidade_frutas(pomares[total_pomares - 1].arvores, pomares[total_pomares - 1].total_arvores);
                break;
            case 6:
                buscar_arvore_por_nome(pomares[total_pomares - 1].arvores, pomares[total_pomares - 1].total_arvores);
                break;
            case 7:
                listar_pomares_e_arvores(pomares, total_pomares);
                break;
            case 8:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 8);

    return 0;
}
