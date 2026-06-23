---
ordem: 6
slug: aula-6
titulo: "Ordenação e Busca em C99"
endereco: "6"
---

### 🔹 1. Busca Linear (Sequencial)

Percorre o vetor do início ao fim até achar o elemento.

```c
#include <stdio.h>

int busca_linear(int v[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (v[i] == x) {
            return i; // retorna o índice onde encontrou
        }
    }
    return -1; // não encontrou
}

int main(void) {
    int v[5] = {4, 2, 9, 7, 1};
    int pos = busca_linear(v, 5, 7);

    if (pos != -1)
        printf("Encontrado na posição %d\n", pos);
    else
        printf("Não encontrado\n");

    return 0;
}
```

🧩 É simples, mas lento para grandes quantidades de dados: O(n).

### 🔹 2. Busca Binária

Funciona somente em vetores ordenados. Divide o vetor ao meio a cada comparação → muito mais rápida (O(log n)).

```c
#include <stdio.h>

int busca_binaria(int v[], int n, int x) {
    int ini = 0, fim = n - 1;

    while (ini <= fim) {
        int meio = (ini + fim) / 2;

        if (v[meio] == x)
            return meio;
        else if (v[meio] < x)
            ini = meio + 1;
        else
            fim = meio - 1;
    }
    return -1;
}

int main(void) {
    int v[6] = {1, 3, 5, 7, 9, 11};
    int pos = busca_binaria(v, 6, 7);

    if (pos != -1)
        printf("Encontrado na posição %d\n", pos);
    else
        printf("Não encontrado\n");

    return 0;
}
```

### ⚙️ Algoritmos de Ordenação

Agora, vamos ordenar vetores. Esses são os mais clássicos e caem em provas, competições e entrevistas.

#### 🔸 1. Bubble Sort

Compara pares vizinhos e troca quando estão fora de ordem. É simples, mas lento (O(n²)).

```c
#include <stdio.h>

void bubble_sort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

int main(void) {
    int v[5] = {5, 3, 1, 4, 2};
    bubble_sort(v, 5);

    printf("Vetor ordenado: ");
    for (int i = 0; i < 5; i++)
        printf("%d ", v[i]);
    printf("\n");

    return 0;
}
```

#### 🔸 2. Selection Sort

Seleciona o menor elemento e o coloca na posição correta a cada passo. Também O(n²), mas faz menos trocas que o Bubble.

```c
#include <stdio.h>

void selection_sort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[min])
                min = j;
        }
        int temp = v[i];
        v[i] = v[min];
        v[min] = temp;
    }
}
```

#### 🔸 3. Insertion Sort

Constrói o vetor ordenado inserindo um elemento de cada vez na posição correta. Muito eficiente para vetores quase ordenados.

```c
#include <stdio.h>

void insertion_sort(int v[], int n) {
    for (int i = 1; i < n; i++) {
        int atual = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > atual) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = atual;
    }
}
```

#### 🔸 4. Comparando na prática

```c
#include <stdio.h>

void bubble_sort(int v[], int n);
void selection_sort(int v[], int n);
void insertion_sort(int v[], int n);

int main(void) {
    int v[6] = {8, 3, 7, 4, 9, 1};
    int opcao;

    printf("1 - Bubble\n2 - Selection\n3 - Insertion\nEscolha: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1: bubble_sort(v, 6); break;
        case 2: selection_sort(v, 6); break;
        case 3: insertion_sort(v, 6); break;
        default: printf("Opção inválida\n"); return 0;
    }

    printf("Vetor ordenado: ");
    for (int i = 0; i < 6; i++)
        printf("%d ", v[i]);
    printf("\n");
    return 0;
}

// Implementações
void bubble_sort(int v[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
}

void selection_sort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (v[j] < v[min])
                min = j;
        int temp = v[i];
        v[i] = v[min];
        v[min] = temp;
    }
}

void insertion_sort(int v[], int n) {
    for (int i = 1; i < n; i++) {
        int atual = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > atual) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = atual;
    }
}
```

### 🧩 Desafio Final

- Leia n números de um vetor (use malloc).
- Pergunte ao usuário se quer ordenar (1) ou buscar (2).
- Se for ordenar → escolha o método e mostre o vetor ordenado.
- Se for buscar → use busca binária (somente depois de ordenar).
- 💡 Extra: compare o tempo de execução entre Bubble e Insertion usando `clock()` da `<time.h>`.
- Liberar a memória no final.
