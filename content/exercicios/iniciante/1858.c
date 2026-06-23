#include <stdio.h>

int main() {
    
    int n, menor = 21, x = 101;
    scanf("%d", &n);
    
    int v[n+1];
    
    for(int i = 1; i <= n; i++) {
        
        scanf("%d", &v[i]);
        
        
        if(v[i] < x) {
            x = v[i];
            menor = i;
        }
    }
    
    printf("%d\n", menor);
    
    return 0;
}
