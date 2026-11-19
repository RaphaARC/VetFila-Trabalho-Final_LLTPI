# Changelog

Todas as mudanças notáveis no projeto **VetFila** serão documentadas neste arquivo.

## - 2026-11-16
### Adicionado
- **Árvore Binária de Busca (`ABB`):**
  - Estrutura `AnimalBusca` (`AnimalABB.hpp`) para os nós da árvore.
  - Métodos para calcular altura (`altura`), quantidade de nós (`quantNos`) e destrutor (`~ABB`) para liberação de memória.
- **Fila (`Fila`):**
  - Método `pesquisarTutor` para busca de animais pelo nome do tutor.
- **Ordenação (`Ordenacao`):**
  - Implementação do algoritmo `selectionSort` ordenado pela frequência de visitas.
- **Métricas:**
  - Contadores de comparações (`ContadoresPesquisa` e `Contadores`) para análise de desempenho.

### Alterado
- Refatoração dos métodos da `ABB` para utilizar `AnimalBusca`.

### Corrigido
- Correções na inserção, busca e remoção completa de nós (folhas, 1 filho e 2 filhos) na `ABB`.
- Correção na diretiva `#define FILA_HPP`.

## - 2026-11-03
### Adicionado
- **Árvore Binária de Busca (`ABB`):**
  - Método `menorValor` para localizar o menor elemento da árvore.
  - Métodos para calcular a altura da árvore (`altura` e `alturaRecursiva`).
  - Métodos para contagem de nós (`quantidadeNos` e `quantidadeNosRecursiva`).
  - Destrutor da árvore e método auxiliar `liberarRecursivo` para gerenciamento de memória.

### Alterado
- Ajustes nos tipos de retorno de métodos existentes da `ABB`.

## - 2026-10-28
### Adicionado
- Configuração inicial do repositório e estrutura base de arquivos do **VetFila** (@RaphaARC).
- **Histórico (Lista Duplamente Encadeada):**
  - Estrutura utilizando `std::list` para armazenar registros de procedimentos e retornos (@RaphaARC).
  - Métodos para adicionar, exibir, consultar tamanho e limpar registros do histórico.
  - Navegação entre registros anteriores e próximos, com verificações de lista vazia e limites.
  - Funcionalidade para desfazer a última ação.
- **Árvore Binária de Busca (`ABB`):**
  - Implementação inicial da estrutura da árvore e definição da classe/struct `Animal` (@Natanael-Soares e @RaphaARC).
