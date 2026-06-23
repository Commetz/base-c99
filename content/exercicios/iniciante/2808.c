#include <stdio.h>
#include <stdlib.h>

int main() {

    char c1, c2;
    int n1, n2;
    scanf("%c%d %c%d", &c1, &n1, &c2, &n2);
    
    int v1 = c1 - '0';
    int v2 = c2 - '0';
    
    if((abs(v1 - v2) == 1 && abs(n1 - n2) == 2) || (abs(v1 - v2) == 2 && abs(n1 - n2) == 1)) {
        printf("VALIDO\n");
    } else {
        printf("INVALIDO\n");
    }
    
    return 0;
}

