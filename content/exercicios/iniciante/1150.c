#include <stdio.h>

int main() {

    int x, z, contador = 1;
    scanf("%d %d", &x, &z);
    
    while(x >= z) {
        scanf("%d", &z);
    }
    
    int y = x;
    int i = 1;

    while(1) {
        y += x + i;
        i++;
        contador++;
        
        if(y > z) {
            break;
        }
    }

    printf("%d\n", contador);

    return 0;
}
