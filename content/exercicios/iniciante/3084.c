#include <stdio.h>

int main() {
    
    int h, m;
    
    while(scanf("%d %d", &h, &m) != EOF) {
        h = h / 30;
        m = m / 6;
        
        if (h < 10) {
            printf("0%d:", h);
        } else {
            printf("%d:", h);
        }
        
        if (m < 10) {
            printf("0%d\n", m);
        } else {
            printf("%d\n", m);
        }
    }
    
    return 0;
}
