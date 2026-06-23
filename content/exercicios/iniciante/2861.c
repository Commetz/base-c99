#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);
    
    char frase[101];
    fgets(frase, 101, stdin);

    for(int i = 0; i < n; i++) {
        fgets(frase, 101, stdin);

        printf("gzuz\n");
    }
    
    return 0;
}
    
