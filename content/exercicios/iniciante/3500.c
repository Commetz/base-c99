#include <stdio.h>

int main() {

    char n[4];

    for(int i = 0; i < 3; i++) {
        scanf("%c", &n[i]);
    }

    printf("Invertido = ");

    for(int i = 2; i >= 0; i--) {
        printf("%c", n[i]);
    }
       
    
    return 0;
}

