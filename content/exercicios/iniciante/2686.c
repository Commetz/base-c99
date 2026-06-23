#include <stdio.h>

int main() {

    double n;
    
    while(scanf("%lf", &n) != EOF) {
        int segundos = n * 240;
        int horas = ((segundos / 3600) + 6) % 24;
        int minutos = (segundos % 3600) / 60;
        int segundo = (segundos % 3600) % 60;

        if(n < 90.0) {
            printf("Bom Dia!!\n");
        } else if(n < 180.0) {
            printf("Boa Tarde!!\n");
        } else if(n < 270.0) {
            printf("Boa Noite!!\n");
        } else {
            printf("De Madrugada!!\n");
        }

        if(horas < 10) {
            printf("0%d:", horas);
        } else {
            printf("%d:", horas);
        }

        if(minutos < 10) {
            printf("0%d:", minutos);
        } else {
            printf("%d:", minutos);
        }

        if(segundo < 10) {
            printf("0%d\n", segundo);
        } else {
            printf("0%d\n", segundo);
        }
    }    
   
    return 0;
}

