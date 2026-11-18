# Changelog

Todas as mudanças notáveis neste projeto serão documentadas neste arquivo.

## - 2026-11-16
### Adicionado
- **Árvore Binária de Busca (`ABB`):**
  - Estrutura `AnimalBusca` (`AnimalABB.hpp`) para os nós da árvore.
  - Métodos para calcular altura (`altura`), quantidade de nós (`quantNos`) e destrutor (`~ABB`) para liberação de memória.
- **Fila (`Fila`):**
  - Método `pesquisarTutor` para busca de animais pelo nome do tutor.
- **Ordenação (Ordenacao):
  - Implementação do algoritmo selectionSort ordenado pela frequência de visitas.
- **Métricas:
  - Contadores de comparações (ContadoresPesquisa e Contadores) para análise de desempenho.

### Alterado
- Refatoração dos métodos da ABB para utilizar AnimalBusca.

### Corrigido
- Correções na inserção, busca e remoção completa de nós (folhas, 1 filho e 2 filhos) na ABB.
- Correção na diretiva #define FILA_HPP.

## - 2026-11-03
### Adicionado
- Pequenas alterações no tipo de retorno de alguns métodos da árvore e adição de outros métodos dentre: menorValor, alturaRecursiva, altura, quantidadeNosRecursiva, quantidadeNos, liberarRecursivo e destrutor da árvore. 

## - 2026-10-28
### Adicionado
- Estrutura inicial do projeto e definição da classe/struct Animal.
- Configuração inicial do repositório.
