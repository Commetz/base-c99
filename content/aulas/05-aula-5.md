---
ordem: 5
slug: aula-5
titulo: "Ponteiros e Alocação Dinâmica"
endereco: "5"
---

### 🔹 1. O que é um ponteiro?

Um ponteiro é uma variável que guarda o endereço de memória de outra variável.

```c
int x = 10;
int *p = &x;  // p aponta para x
```

```c
#include <stdio.h>

int main(void) {
    int x = 10;
    int *p = &x;

    printf("Valor de x: %d\n", x);
    printf("Endereço de x: %p\n", &x);
    printf("Valor de p (endereço armazenado): %p\n", p);
    printf("Valor apontado por p: %d\n", *p);

    *p = 20; // altera o valor de x através do ponteiro
    printf("Novo valor de x: %d\n", x);

    return 0;
}
```

⚡ Símbolos importantes:

- `&` → endereço da variável
- `*` → valor contido no endereço (desreferenciação)

### 🔹 2. Ponteiros e funções

Ponteiros permitem modificar variáveis fora da função (passagem por referência).

```c
#include <stdio.h>

void dobrar(int *n) {
    *n = *n * 2; // acessa e modifica o valor original
}

int main(void) {
    int x = 5;
    dobrar(&x);
    printf("Valor dobrado: %d\n", x);
    return 0;
}
```

### 🔹 3. Ponteiros e vetores

Em C, o nome de um vetor já é um ponteiro para o primeiro elemento.

```c
#include <stdio.h>

int main(void) {
    int v[3] = {10, 20, 30};
    int *p = v; // equivale a &v[0]

    printf("%d\n", *p);       // 10
    printf("%d\n", *(p + 1)); // 20
    printf("%d\n", *(p + 2)); // 30
    return 0;
}
```

O ponteiro anda na memória conforme o tipo. `p + 1` vai para o próximo inteiro, não para o próximo byte.

### 🔹 4. Ponteiros para ponteiros

```c
#include <stdio.h>

int main(void) {
    int x = 42;
    int *p = &x;
    int **pp = &p;

    printf("%d\n", **pp); // acessa o valor final
    return 0;
}
```

## 🧩 Parte 2 – Alocação Dinâmica de Memória

Em vez de criar variáveis fixas, você pode pedir memória durante a execução. Biblioteca necessária: `<stdlib.h>`

### 🔹 malloc()

Aloca um bloco de memória sem inicializar.

```c
int *p = malloc(5 * sizeof(int));
```

O tamanho deve ser dado em bytes → `sizeof(tipo)` ajuda a garantir portabilidade.

### 🔹 calloc()

Semelhante ao malloc(), mas inicializa a memória com zero.

```c
int *p = calloc(5, sizeof(int));
```

### 🔹 realloc()

Redimensiona um bloco já alocado.

```c
p = realloc(p, 10 * sizeof(int));
```

### 🔹 free()

Libera a memória quando não for mais usada.

```c
free(p);
p = NULL; // boa prática: evita ponteiro solto
```

### 🔹 Exemplo completo de vetor dinâmico

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int *v = malloc(n * sizeof(int));

    if (v == NULL) {
        printf("Erro de alocação!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        v[i] = i + 1;
    }

    printf("Vetor alocado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }

    free(v);
    return 0;
}
```

### 🔹 Matrizes dinâmicas (nível intermediário)

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int linhas = 3, colunas = 3;

    int **matriz = malloc(linhas * sizeof(int*));
    for (int i = 0; i < linhas; i++) {
        matriz[i] = malloc(colunas * sizeof(int));
    }

    // Preenchimento
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriz[i][j] = i + j;
        }
    }

    // Exibição
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Liberação
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
```

### 🧩 Desafio da Aula 5

- Peça ao usuário um número `n`.
- Alocar dinamicamente um vetor de `n` posições.
- Ler os números e calcular a média.
- Mostrar todos os números acima da média.
- Liberar a memória no final.
- 💡 Extra: transforme o mesmo programa para usar matriz dinâmica NxM.
