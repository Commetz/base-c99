#include <stdio.h>

int main() {

    int n, v[50];
    scanf("%d", &n);

    v[0] = 1;
    v[1] = 1;

    for(int i = 2; i < n; i++) {
        v[i] = v[i-1] + v[i-2];
    }
    
    printf("%d", v[n - 1]);

    for(int i = n - 2; i >= 0; i--) {
        printf(" %d", v[i]);    
    }

    printf("\n");
    
    return 0;
}

