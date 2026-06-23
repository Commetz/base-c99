#include <stdio.h>

int main() {

    int x, cont = 0;
    scanf("%d", &x);

    for(int i = x; cont < 6; i++) {
        if(i % 2 != 0) {
            printf("%d\n", i);
            cont++;
        }
    } 
    
    return 0;
}
