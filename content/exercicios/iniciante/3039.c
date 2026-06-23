#include <stdio.h>

int main() {
    
    int n;
    scanf("%d", &n);
    
    int f = 0, m = 0;
    
    for(int i = 0; i < n; i++) {
        char s[100], g;
        scanf("%s %c", s, &g);
        
        if(g == 'F') {
            f++;
        } else {
            m++;
        }
    }
    
    printf("%d carrinhos\n%d bonecas\n", m, f);
    
    return 0;
}
