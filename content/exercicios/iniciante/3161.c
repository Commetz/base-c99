#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXM 505
#define MAXL 105

char lista[MAXM][MAXL];

void to_lower_str(char *s) {
    for (int i = 0; s[i]; i++) {
        s[i] = (char)tolower((unsigned char)s[i]);
    }
}

void reverse_str(const char *src, char *dst) {
    int n = strlen(src);
    for (int i = 0; i < n; i++) {
        dst[i] = src[n - 1 - i];
    }
    dst[n] = '\0';
}

int main() {
    int N, M;

    while (scanf("%d %d", &N, &M) == 2) {

        for (int i = 0; i < N; i++) {
            scanf("%s", lista[i]);
            to_lower_str(lista[i]);
        }

        char linhas[MAXM][MAXL];

        for (int i = 0; i < M; i++) {
            scanf("%s", linhas[i]);
            to_lower_str(linhas[i]);
        }

        for (int i = 0; i < N; i++) {
            char fruta[MAXL];
            strcpy(fruta, lista[i]);

            char inv[MAXL];
            reverse_str(fruta, inv);

            int gosta = 0;

            for (int j = 0; j < M && !gosta; j++) {
                if (strstr(linhas[j], fruta) != NULL ||
                    strstr(linhas[j], inv) != NULL) {
                    gosta = 1;
                }
            }

            if (gosta)
                printf("Sheldon come a fruta %s\n", fruta);
            else
                printf("Sheldon detesta a fruta %s\n", fruta);
        }
    }

    return 0;
}
