#include <stdio.h>

int main() {
    
    int n;
    while(scanf("%d", &n) != EOF) {
        int maior  = -1;
        for(int i = 0; i < n; i++) {
            int v;
            scanf("%d", &v);
            
            if(maior <= v) {
                maior = v;
            }
        }
        
        if(maior >= 20) {
            printf("3\n");
        } else if (maior >= 10) {
            printf("2\n");
        } else {
            printf("1\n");
        }
    }
    
    
    
    return 0;
}
