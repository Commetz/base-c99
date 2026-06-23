#include <stdio.h>

int main() {
    int d1, h1, m1, s1;
    int d2, h2, m2, s2;

    char linha[50];

    // Dia 1
    fgets(linha, sizeof(linha), stdin);
    sscanf(linha, "Dia %d", &d1);

    // Hora 1
    fgets(linha, sizeof(linha), stdin);
    sscanf(linha, "%d : %d : %d", &h1, &m1, &s1);

    // Dia 2
    fgets(linha, sizeof(linha), stdin);
    sscanf(linha, "Dia %d", &d2);

    // Hora 2
    fgets(linha, sizeof(linha), stdin);
    sscanf(linha, "%d : %d : %d", &h2, &m2, &s2);

    int t1 = d1*86400 + h1*3600 + m1*60 + s1;
    int t2 = d2*86400 + h2*3600 + m2*60 + s2;

    int dt = t2 - t1;

    int d = dt / 86400;
    int h = (dt % 86400) / 3600;
    int m = (dt % 3600) / 60;
    int s = dt % 60;

    printf("%d dia(s)\n%d hora(s)\n%d minuto(s)\n%d segundo(s)\n", d, h, m, s);

    return 0;
}
