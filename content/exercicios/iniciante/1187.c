#include <stdio.h>

int main() {

    double m[12][12];
    char t[1];
    scanf(" %c", &t[0]);

    double soma = 0, media = 0;
    int cont = 0;

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            scanf("%lf", &m[i][j]);
        }
    }

    if (t[0] == 'S') {
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 12; j++) {
                if (j > i && i + j < 11) {
                    soma += m[i][j];
                }
            }
        }
        printf("%.1lf\n", soma);
    } else {
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 12; j++) {
                if (j > i && i + j < 11) {
                    soma += m[i][j];
                    cont++;
                }
            }
        }
        media = soma / cont;
        printf("%.1lf\n", media);
    }

    return 0;
}

