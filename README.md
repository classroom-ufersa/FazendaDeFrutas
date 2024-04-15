### Sobre o Projeto: Gerenciamento de Fazenda de Frutas 🍎🍐🍊
Este projeto visa facilitar o gerenciamento de uma fazenda de frutas, oferecendo uma plataforma intuitiva e eficiente para monitorar e administrar pomares e árvores de frutas. Desenvolvido como parte da disciplina de Algoritmos e Estrutura de Dados 1, sob a orientação da professora Rosana Cibely Batista Rego, o sistema foi implementado em linguagem C.

### Desenvolvedores 👨‍💻👨‍💻
- [Dinarte Rodrigues de Oliveira Filho](https://github.com/dinarteefilho)
- [Samuel de Almeida Saturno](https://github.com/Samuel-Saturno)

### Funcionalidades 🛠️
1. ´**Adicionar Pomar**´: Permite a inserção de um novo pomar na fazenda.
2. ´**Remover Pomar**´: Remove um pomar existente da lista.
3. ´**Adicionar Árvore**´: Adiciona uma nova árvore ao pomar selecionado.
4. ´**Remover Árvore**´: Remove uma árvore específica de um pomar.
5. ´**Alterar Quantidade de Frutas**´: Modifica a quantidade de frutas de uma árvore.
6. ´**Buscar Árvore por Nome**´: Localiza uma árvore na fazenda pelo nome.
7. ´**Listar Pomares e Árvores**´: Exibe todos os pomares e suas respectivas árvores.
8. ´**Sair**´: Encerra a execução do programa.

### Funcionamento 🔄
1. **TADs Utilizadas:** O sistema é baseado em duas TADs: "Pomares" e "Árvores".
   - A TAD "Pomares" armazena a identificação e a área de plantio de cada pomar.
   - A TAD "Árvores" registra o nome, tipo, quantidade de frutas e idade de cada árvore.

2. **Armazenamento de Dados:** Os dados dos pomares e das árvores são armazenados em arquivos de texto (.txt), garantindo a persistência das informações.

3. **Ordenação:** A ordenação dos elementos nas listas é realizada através do algoritmo de inserção (insertion sort), garantindo eficiência na organização dos dados.

4. **Busca:** A busca por árvores é feita de forma sequencial, oferecendo uma abordagem simples e direta para encontrar elementos na fazenda.

### Organização
´´´
📁 FAZENDADEFRUTAS [GITHUB]
|_📁TADarvore
  |_🌳arvore.c
  |_🌳arvore.h
|_📁TADpomares
  |_💾listapomares.txt
  |_🌳pomares.c
  |_🌳pomares.h

⭐ main.c
📍 README.md
´´´