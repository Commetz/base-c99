#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);

    int a, b; 
    scanf("%d %d", &a, &b);

    if(a + b <= n) {
        printf("Farei hoje!\n");
    } else {
        printf("Deixa para amanha!\n");
    }
    
    return 0;
}
