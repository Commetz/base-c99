// 1222 Beecrowd - Concurso de Contos
// Por Commetz
#include <stdio.h>
// Incluindo a biblioteca de string
#include <string.h>

// Função principal para ler o código de figurinhas
#define true 1
#define false 0
#define MAXSIZE 70

int main () {

    int i, l, c, n, x;
    int linhas, paginas, letras;
    char palavra[MAXSIZE + 1];

    // Laço de repeticao para os casos de teste
    while (scanf("%d %d %d", &n, &l, &c) != EOF) {
        paginas = linhas = 1;
        scanf("%s", palavra);
        // Conta o numero de letras da palavra
        letras = strlen(palavra);
        n--;

        // Laço de repeticao para cada figurinha
        for (i = 0; i < n; ++i) {
            scanf("%s", palavra);
            // Conta o numero de letras da palavra
            x = strlen(palavra); 
            
            // Se a letra for maior que o limite, a pagina é incrementada
            if ((letras + x + 1) <= c) 
                letras += x + 1;
            else {
                ++linhas;
                // Se a pagina for maior que o limite, a pagina é incrementada
                if (linhas > l) 
                    ++paginas, linhas = 1;
                letras = x;
            }
        }

        printf("%d\n", paginas);

    }
}
