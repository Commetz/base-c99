#include <stdio.h>

int main() {

    int a, b, c, d, e; 
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

    if((d == 1 && e == 0) || (d == 0 && e == 1)) {
        printf("Jogador 1 ganha!\n");
    } else if(d == 1 && e == 1) {
        printf("Jogador 2 ganha!\n");
    } else {
        if((a == 1 && (b + c) % 2 == 0) || (a == 0 && (b + c) % 2 != 0)) {
            printf("Jogador 1 ganha!\n");
        } else {
            printf("Jogador 2 ganha!\n");
        }
    }

    return 0;
}
