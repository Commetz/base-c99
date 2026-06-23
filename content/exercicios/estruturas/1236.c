// 1236 Beecrowd - Compactação de Nulos e Brancos
// Por Commetz
#include <stdio.h>
// Incluindo a biblioteca de string
#include <string.h>

// Definindo o tamanho do vetor 
void compact(char *input, char *output) {
    
    int len = strlen(input);
    int outIdx = 0;

    // Percorrendo o vetor de entrada
    for (int i = 0; i < len; i++) {
        char current = input[i];
        int count = 1;

        // Contar a quantidade de espaços ou zeros seguidos
        while (i + 1 < len && input[i + 1] == current && (current == ' ' || current == '0')) {
            count++;
            i++;
        }

        if (current == ' ' && count > 2) {
            // Compactação de espaços em branco
            while (count > 0) {
                int freq = count > 255 ? 255 : count;
                output[outIdx++] = '$';
                output[outIdx++] = (char)freq;
                count -= freq;
            }
        } else if (current == '0' && count > 2) {
            // Compactação de zeros
            while (count > 0) {
                int freq = count > 255 ? 255 : count;
                output[outIdx++] = '#';
                output[outIdx++] = (char)freq;
                count -= freq;
            }
        } else {
            // Não compacta, apenas copia os caracteres
            while (count-- > 0) {
                output[outIdx++] = current;
            }
        }
    }
    // Finaliza a string compactada
    output[outIdx] = '\0'; 
}

int main() {
    
    int N;
    scanf("%d\n", &N);

    for (int i = 0; i < N; i++) {
        // Output pode ter até o dobro do tamanho
        char input[2001], output[4002]; 
        fgets(input, 2001, stdin);

        // Remover o '\n' ao final da string de input
        input[strcspn(input, "\n")] = '\0';

        // Chamar a função compact
        compact(input, output);
        printf("%s\n", output);
    }

    return 0;
}
