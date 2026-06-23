---
ordem: 1
slug: aula-1
titulo: "Sintaxe Básica do C99"
endereco: "1"
---

### Estrutura mínima de um programa

Um programa em C99 sempre tem uma função principal `main`, onde a execução começa.

```c
#include <stdio.h>

int main(void) {
    printf("Olá, Gabriel!\n");
    return 0;
}
```

### Declaração de variáveis

```c
int idade = 19;       // número inteiro
float altura = 1.75;  // número real
char letra = 'G';     // caractere único
```

> ⚠️ **Lembre-se:** C é fortemente tipado — não dá pra trocar o tipo depois.

### Entrada e saída

```c
#include <stdio.h>

int main(void) {
    int x;
    printf("Digite um número: ");
    scanf("%d", &x);
    printf("Você digitou: %d\n", x);
    return 0;
}
```

### Formatos principais do scanf/printf

| Tipo   | Descrição  | Formato |
|--------|------------|---------|
| int    | Inteiro    | %d      |
| float  | Real       | %f      |
| double | Real duplo | %lf     |
| char   | Caractere  | %c      |
| char[] | String     | %s      |

### Operadores básicos

| Categoria   | Exemplos          | Descrição                                       |
|-------------|--------------------|--------------------------------------------------|
| Aritméticos | + - * / %          | soma, subtração, multiplicação, divisão, resto  |
| Relacionais | == != > < >= <=    | comparações                                      |
| Lógicos     | && \|\| !          | operações lógicas                                |
| Atribuição  | = += -= *= /=      | atribui ou atualiza valores                      |

### Comentários

```c
// comentário de uma linha

/*
comentário
de várias linhas
*/
```

### Desafio da Aula 1

Escreva um programa que:

- Leia dois números inteiros.
- Mostre a soma, diferença, produto e quociente entre eles (com duas casas decimais).

> 💡 **Dica:** use `%.2f` para limitar as casas decimais.
