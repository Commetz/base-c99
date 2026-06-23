#include <stdio.h>

int bissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

void adiciona_dias(int ano, int mes, int dia, int dias) {
    int dim[] = {0, 31,28,31,30,31,30,31,31,30,31,30,31};

    while (dias > 0) {
        dim[2] = bissexto(ano) ? 29 : 28;
        int resto_mes = dim[mes] - dia;
        if (dias <= resto_mes) {
            dia += dias;
            dias = 0;
        } else {
            dias -= resto_mes + 1;
            dia = 1;
            mes++;
            if (mes > 12) { mes = 1; ano++; }
        }
    }
    printf("%04d-%02d-%02d\n", ano, mes, dia);
}

int main() {
    
    int N;
    scanf("%d", &N);

    int dias_jup = (int)(N * 11.9 * 365.25);
    int dias_sat = (int)(N * 29.6 * 365.25);

    printf("Dias terrestres para Jupiter = %d\n", dias_jup);
    printf("Data terrestre para Jupiter: ");
    adiciona_dias(2020, 12, 21, dias_jup);

    printf("Dias terrestres para Saturno = %d\n", dias_sat);
    printf("Data terrestre para Saturno: ");
    adiciona_dias(2020, 12, 21, dias_sat);

    return 0;
}
