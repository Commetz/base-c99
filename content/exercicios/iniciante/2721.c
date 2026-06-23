#include <stdio.h>

int main() {

    int cont = 0;

    for(int i = 0; i < 9; i++) {
        int x; 
        scanf("%d", &x);

        cont += x;     
    }
    
    int r = cont % 9;

    if(r == 1) {
        printf("Dasher\n");
    } else if(r == 2) {
        printf("Dancer\n");
    } else if(r == 3) {
        printf("Prancer\n");
    } else if(r == 4) {
        printf("Vixen\n");
    } else if(r == 5) {
        printf("Comet\n");
    } else if(r == 6) {
        printf("Cupid\n");
    } else if(r == 7) {
        printf("Donner\n");
    } else if(r == 8) {
        printf("Blitzen\n");
    } else if(r == 9 || r == 0) {
        printf("Rudolph\n");
    }
    
    return 0;
}
