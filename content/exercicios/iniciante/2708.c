#include <stdio.h>
#include <string.h>

int main() {

    int salida = 0;
    int vuelta = 0;
    
    int conts = 0;
    int contv = 0;

    while(1) {
        char palavra[11];
        scanf("%s", palavra);
    
        if(strcmp(palavra, "ABEND") == 0) {
            printf("%d\n%d\n", conts - contv, salida - vuelta);
            return 0;
        } else if(strcmp(palavra, "SALIDA") == 0) {
            salida++;
            int x;
            scanf("%d", &x);
            conts += x;
        } else if(strcmp(palavra, "VUELTA") == 0) {
            vuelta++;
            int x;
            scanf("%d", &x);
            contv += x;
        }


    }

    return 0;
}   
