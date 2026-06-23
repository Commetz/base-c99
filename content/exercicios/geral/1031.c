// 1031 Beecrowd - Crise de Energia
// Por Commetz
#include <stdio.h>

// Declarando as variáveis
int T[101][1001];

// Função para calcular a posição que salva o 13º termo
int posicao_segura(int i, int k) {
    if(T[i][k] == -1) {
        T[i][k] = (posicao_segura(i - 1, k) + k) % i;
    }
    return T[i][k];
}

int main() {

    int n, m;

    // Inicia a tabela para memoização
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < 1001; ++j) {
            T[i][j] = 0;
        }
    }

    for(int i = 2; i < 101; ++i) {
        for(int j = 0; j < 1001; ++j) {
            T[i][j] = -1;
        }   
    }

    // Lê o número de pessosas até encontrar o EOF
    while(scanf("%d", &n) != EOF) {
        if(!n)  break;
        m = 1;

        // Aumenta m até que a pocição segura seja 13
        while((posicao_segura(n - 1, m) + 1) % n != 12) {
            ++m;
        }

        printf("%d\n", m);
    }

    return 0;
}
