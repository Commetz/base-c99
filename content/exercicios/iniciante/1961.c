#include <stdio.h>

int main() {

    int x, y, ult = 0, cont = 0;
    scanf("%d %d", &x, &y);

    for(int i = 0; i < y; i++) {
        int altura;
        scanf("%d", &altura);

        if(altura - ult > x) {
            cont = 1;
        }

        ult = altura;
    } 

    if(cont == 0) {
        printf("YOU WIN\n");
    } else {
        printf("GAME OVER\n");
    }
     
    return 0;
}   

