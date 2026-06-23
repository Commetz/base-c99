#include <stdio.h>
#include <string.h>

int main() {
    
    int n;
    scanf("%d", &n);
    
    for(int i = 0; i <= n; i++) {
        char linha[200];
        
        if (fgets(linha, sizeof(linha), stdin)) {
            linha[strcspn(linha, "\n")] = '\0';
    }
        
    }
    
    printf("Ciencia da Computacao\n");
    
    return 0;
}
