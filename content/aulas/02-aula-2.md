---
ordem: 2
slug: aula-2
titulo: "Estruturas de Decisão e Repetição"
endereco: "2"
---

### Estruturas de Decisão

#### ✅ if / else

Executa um bloco se a condição for verdadeira, senão outro bloco.

```c
#include <stdio.h>

int main(void) {
    int idade;
    printf("Digite sua idade: ");
    scanf("%d", &idade);

    if (idade >= 18) {
        printf("Maior de idade.\n");
    } else {
        printf("Menor de idade.\n");
    }

    return 0;
}
```

> ⚠️ As chaves `{}` são opcionais para um bloco de uma linha, mas é recomendado sempre usar.

#### ✅ if / else if / else

Usado quando há múltiplas condições possíveis.

```c
#include <stdio.h>

int main(void) {
    int nota;
    printf("Digite sua nota: ");
    scanf("%d", &nota);

    if (nota >= 90) {
        printf("Aprovado com A\n");
    } else if (nota >= 70) {
        printf("Aprovado com B\n");
    } else if (nota >= 50) {
        printf("Aprovado com C\n");
    } else {
        printf("Reprovado\n");
    }

    return 0;
}
```

#### ✅ switch / case

Mais eficiente que vários if/else quando se compara um valor fixo.

```c
#include <stdio.h>

int main(void) {
    int opcao;
    printf("1 - Café\n2 - Chá\n3 - Suco\nEscolha: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("Você escolheu café.\n");
            break;
        case 2:
            printf("Você escolheu chá.\n");
            break;
        case 3:
            printf("Você escolheu suco.\n");
            break;
        default:
            printf("Opção inválida.\n");
    }

    return 0;
}
```

> ⚠️ Nunca esqueça do `break`, senão o programa continua executando os próximos `case`.

### Estruturas de Repetição

#### 🔸 while

Repete enquanto a condição for verdadeira.

```c
#include <stdio.h>

int main(void) {
    int i = 1;
    while (i <= 5) {
        printf("%d\n", i);
        i++;
    }
    return 0;
}
```

#### 🔸 do / while

Garante pelo menos uma execução, mesmo que a condição seja falsa no início.

```c
#include <stdio.h>

int main(void) {
    int senha;
    do {
        printf("Digite a senha (1234): ");
        scanf("%d", &senha);
    } while (senha != 1234);

    printf("Acesso permitido!\n");
    return 0;
}
```

#### 🔸 for

Mais usado quando sabemos o número de repetições.

```c
#include <stdio.h>

int main(void) {
    for (int i = 0; i < 5; i++) {
        printf("Valor de i: %d\n", i);
    }
    return 0;
}
```

Estrutura: `for (inicialização; condição; incremento)`

### Comandos úteis dentro de laços

| Comando  | Função                                                 |
|----------|----------------------------------------------------------|
| break    | Encerra o laço imediatamente                              |
| continue | Pula o restante do laço e vai para a próxima iteração     |

```c
#include <stdio.h>

int main(void) {
    for (int i = 1; i <= 10; i++) {
        if (i == 5) continue; // pula o 5
        if (i == 8) break;    // para no 8
        printf("%d ", i);
    }
    return 0;
}
```

Saída: `1 2 3 4 6 7`

### Desafio da Aula 2

Escreva um programa que:

- Leia um número `n`.
- Some todos os números de 1 até `n` usando `for` e mostre o resultado.
- Tente reescrever usando `while`.
