#include <stdio.h>

int main() {

    int a, b, c; 
    scanf("%d %d %d", &a, &b, &c);

    int cont1, cont2, cont3;
    cont1 = ((b * 1 + c * 2) * 2);
    cont2 = ((a * 1 + c * 1) * 2);
    cont3 = ((a * 2 + b * 1) * 2);

    if(cont1 <= cont2 && cont1 <= cont3) {
        printf("%d\n", cont1);
    } else if (cont2 <= cont1 && cont2 <= cont3) {
        printf("%d\n", cont2);
    } else if (cont3 <= cont1 && cont3 <= cont2) {
        printf("%d\n", cont3);
    }
    
    return 0;
}   
