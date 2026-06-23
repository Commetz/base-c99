#include <stdio.h>

int main() {
    
    int n;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        
        if(x >= 200 && x <= 300 && y >= 50 && z >= 150) {
            printf("Sim\n");
        } else {
            printf("Nao\n");
        }
    }
    
    return 0;
}
