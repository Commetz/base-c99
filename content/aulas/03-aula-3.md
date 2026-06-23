---
ordem: 3
slug: aula-3
titulo: "Variáveis Compostas em C99"
endereco: "3"
---

Em C, variáveis compostas permitem armazenar vários valores do mesmo tipo. Os principais são:

- **Vetores** (arrays unidimensionais)
- **Matrizes** (arrays bidimensionais)
- **Strings** (arrays de char)

### 🔹 Vetores (arrays)

Um vetor é uma sequência contígua de elementos do mesmo tipo.

```c
#include <stdio.h>

int main(void) {
    int numeros[5]; // vetor de 5 inteiros

    // Leitura
    for (int i = 0; i < 5; i++) {
        printf("Digite o número %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    // Exibição
    printf("Valores digitados: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numeros[i]);
    }

    return 0;
}
```

🧩 Importante: os índices começam em 0 e vão até `tamanho-1`.

#### 🔸 Inicialização direta

```c
int notas[4] = {8, 9, 7, 10};
int notas2[] = {8, 9, 7, 10}; // compilador deduz o tamanho
```

### 🔹 Matrizes (arrays bidimensionais)

Uma matriz é como uma tabela com linhas e colunas.

```c
#include <stdio.h>

int main(void) {
    int matriz[2][3]; // 2 linhas, 3 colunas

    // Leitura
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Exibição
    printf("\nMatriz digitada:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
```

⚙️ A memória da matriz é contígua, mas indexada em duas dimensões.

### 🔹 Strings

Strings em C são vetores de caracteres terminados por `'\0'` (caractere nulo).

```c
#include <stdio.h>

int main(void) {
    char nome[20]; // até 19 letras + '\0'

    printf("Digite seu nome: ");
    scanf("%s", nome); // lê até o primeiro espaço

    printf("Olá, %s!\n", nome);
    return 0;
}
```

> ⚠️ `scanf("%s")` não lê espaços. Para nomes completos, use `fgets()`:

```c
fgets(nome, 20, stdin);
```

#### 🔸 Manipulação básica de strings

```c
#include <stdio.h>
#include <string.h>

int main(void) {
    char palavra1[20] = "C99";
    char palavra2[20];

    strcpy(palavra2, palavra1);      // copia
    strcat(palavra2, " é legal");    // concatena
    printf("%s\n", palavra2);        // exibe
    printf("Tamanho: %lu\n", strlen(palavra2)); // tamanho

    return 0;
}
```

### 🔹 Vetores e funções matemáticas

A biblioteca `<math.h>` traz funções úteis:

| Função             | Descrição                       |
|---------------------|----------------------------------|
| sqrt(x)             | Raiz quadrada                    |
| pow(x, y)           | Potência                         |
| fabs(x)             | Valor absoluto (float)           |
| ceil(x) / floor(x)  | Arredondamento para cima/baixo   |

```c
#include <stdio.h>
#include <math.h>

int main(void) {
    float valores[3] = {4.0, 9.0, 16.0};

    for (int i = 0; i < 3; i++) {
        printf("Raiz de %.1f = %.1f\n", valores[i], sqrt(valores[i]));
    }

    return 0;
}
```

### Desafio da Aula 3

- Leia 5 números reais e armazene em um vetor.
- Calcule a média dos valores.
- Mostre todos os números maiores que a média.
- 💡 Extra: faça uma matriz 3×3 e calcule a soma da diagonal principal.
