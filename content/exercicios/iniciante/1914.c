#include <stdio.h>
#include <string.h>

int main() {
    
    int n;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        char nome1[20], nome2[20], escolha1[20], escolha2[20];
        scanf("%s %s %s %s", nome1, escolha1, nome2, escolha2);
        
        int x, y;
        scanf("%d %d", &x, &y);
        
        if(((x + y) % 2 == 0 && strcmp(escolha1, "PAR") == 0) || ((x + y) % 2 != 0 && strcmp(escolha1, "IMPAR") == 0)) {
            printf("%s\n", nome1);
        } else {
            printf("%s\n", nome2);
        }
    }
    
    
    return 0;
}
