## Mochila de Sobrevivencia (Lista Linear)

Programa em C para gerenciar uma mochila de sobrevivencia usando uma lista linear (vetor). Este projeto foi feito para estudo.

### Funcionalidades
- Adicionar item (nome, tipo e quantidade).
- Remover item pelo nome.
- Listar todos os itens cadastrados.
- Buscar item pelo nome.

### Estrutura de dados
- Vetor fixo com capacidade para 10 itens.
- Cada item possui `nome`, `tipo` e `quantidade`.

### Como compilar
Use um compilador C (ex.: GCC):

```bash
gcc lista-linear.c -o mochila
```

### Como executar
```bash
./mochila
```

### Observacoes
- Entradas de texto usam `scanf` sem espacos (ex.: "kit_medico").
- A capacidade maxima da mochila e 10 itens.

