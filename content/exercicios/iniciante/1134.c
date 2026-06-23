#include <stdio.h>

int main() {

    int x = 3, a = 0, g = 0, d = 0;

    while(x > 0 || x < 4) {
        scanf("%d", &x);
        if(x == 1) {
            a++;
        }
        else if (x == 2) {
            g++;
        }
        else if(x == 3) {
            d++;
        }
        else if(x == 4) {
            break;
        }
    }

    printf("MUITO OBRIGADO\n");
    printf("Alcool: %d\n", a);
    printf("Gasolina: %d\n", g);
    printf("Diesel: %d\n", d);

    return 0;
}
