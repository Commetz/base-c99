---
ordem: 4
slug: aula-4
titulo: "Modularização em C99"
endereco: "4"
---

A modularização é o processo de dividir um programa em partes menores (funções). Isso deixa o código mais limpo, reutilizável e fácil de manter.

### 🔹 Estrutura básica de uma função

`tipo_de_retorno nome_da_funcao(parâmetros) { /* corpo */ return valor; }`

```c
#include <stdio.h>

// Função que soma dois inteiros
int soma(int a, int b) {
    return a + b;
}

int main(void) {
    int x = 10, y = 5;
    int resultado = soma(x, y);
    printf("Soma = %d\n", resultado);
    return 0;
}
```

### 🔹 Tipos de funções

| Tipo           | Exemplo                          | Descrição                |
|----------------|------------------------------------|---------------------------|
| void           | void mensagem()                    | Não retorna nada           |
| com retorno    | int soma()                         | Retorna um valor           |
| com parâmetros | float media(float a, float b)      | Recebe valores externos    |

#### ✅ Exemplo: função sem retorno e sem parâmetros

```c
void saudacao(void) {
    printf("Olá, Gabriel!\n");
}

int main(void) {
    saudacao();
    return 0;
}
```

#### ✅ Exemplo: função com retorno e parâmetros

```c
#include <stdio.h>

int quadrado(int n) {
    return n * n;
}

int main(void) {
    printf("Quadrado de 5 = %d\n", quadrado(5));
    return 0;
}
```

### 🔹 Escopo de variáveis

Variáveis locais → existem apenas dentro da função.
Variáveis globais → declaradas fora de qualquer função.

```c
#include <stdio.h>

int global = 10;

void mostrar(void) {
    int local = 5;
    printf("Global = %d | Local = %d\n", global, local);
}

int main(void) {
    mostrar();
    return 0;
}
```

> ⚠️ Use variáveis globais com moderação — elas dificultam o controle do estado do programa.

### 🔹 Passagem de parâmetros

Por padrão, em C, os parâmetros são passados por valor (uma cópia é feita). Para alterar a variável original, usamos ponteiros (veremos melhor na Aula 5).

```c
#include <stdio.h>

void dobra(int n) {
    n = n * 2;
}

int main(void) {
    int x = 10;
    dobra(x);
    printf("%d\n", x); // ainda é 10
    return 0;
}
```

A variável não muda no main porque apenas uma cópia foi alterada.

### 🔹 Declaração antecipada (protótipo de função)

```c
#include <stdio.h>

int soma(int a, int b); // protótipo

int main(void) {
    printf("%d\n", soma(3, 4));
    return 0;
}

int soma(int a, int b) {
    return a + b;
}
```

Permite organizar funções em arquivos separados.

### 🔹 Arquivos múltiplos

Em projetos grandes, usamos:

- Arquivos `.c` → implementações
- Arquivos `.h` → cabeçalhos (declarações e protótipos)

#### Exemplo de estrutura

Arquivos: `main.c`, `funcoes.c`, `funcoes.h`

**funcoes.h**

```c
#ifndef FUNCOES_H
#define FUNCOES_H

int soma(int a, int b);
void mensagem(void);

#endif
```

**funcoes.c**

```c
#include <stdio.h>
#include "funcoes.h"

int soma(int a, int b) {
    return a + b;
}

void mensagem(void) {
    printf("Bem-vindo ao programa modular!\n");
}
```

**main.c**

```c
#include "funcoes.h"

int main(void) {
    mensagem();
    printf("Resultado: %d\n", soma(2, 3));
    return 0;
}
```

**Compilação (terminal)**

```bash
gcc main.c funcoes.c -o programa
```

### Desafio da Aula 4

- Crie um programa dividido em 3 arquivos (`main.c`, `operacoes.c`, `operacoes.h`).
- Leia dois números inteiros.
- Tenha funções para soma, subtração, multiplicação e divisão.
- Mostre todos os resultados.
- 💡 Extra: adicione uma função que indique qual número é maior.
