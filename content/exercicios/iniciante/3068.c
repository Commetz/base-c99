#include <stdio.h>

int main() {
    
    int x1, y1, x2, y2, i = 1;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    
    while(x1 != 0 && y1 != 0 && x2 != 0 && y2 != 0) {
        int n, cont = 0;
        scanf("%d", &n);
        
        int x, y;
        for(int i = 0; i < n; i++) {
            scanf("%d %d", &x, &y);
            
            if(x >= x1 && x <= x2 && y >= y2 && y <= y1) {
                cont++;
            }
        }
        
        printf("Teste %d\n", i);
        printf("%d\n", cont);
        
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        
        i++;
    }
    
    return 0;
}
