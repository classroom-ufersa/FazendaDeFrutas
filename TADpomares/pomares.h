typedef struct pomar Pomar;

Pomar * cria_lista_pomar(void);

Pomar * insere_pomar_lista(Pomar * lista, int identificacao, float area_plantio, char arvore_presente[], int total_arvores);

Pomar * carrega_pomar_arquivo(char arquivo_nome[]);

void insere_pomar_arquivo(char arquivo_nome[], Pomar * lista);

void libera_lista_pomares(Pomar * lista);

void adiciona_pomar(char arquivo_nome[]);

void imprime_dados_pomar(Pomar * lista);

int remove_pomar(char arquivo_nome[], int id_pomar);
