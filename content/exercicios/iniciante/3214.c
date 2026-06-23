#include <stdio.h>

int main() {

    int e, f, c;
    scanf("%d %d %d", &e, &f, &c);

    int a, cont = 0;
    a = e + f;
    
    for(int i = 0; i < 11; i++) {
        cont += a / c;
        a = (a / c) + (a % c);
    }
    
    printf("%d\n", cont);

    return 0;
}

