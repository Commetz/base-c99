#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int cont0 = 0, cont1 = 0;
        for(int j = 0; j < 3; j++) {
            int x, y; 
            scanf("%d %d", &x, &y);

            cont0 += x * y; 
        }
        
        for(int j = 0; j < 3; j++) {
            int x, y; 
            scanf("%d %d", &x, &y);

            cont1 += x * y; 
        }
        
        if(cont0 > cont1) {
            printf("JOAO\n");
        } else if(cont1 > cont0) {
            printf("MARIA\n");
        }
    }
    
    
    return 0;
}
