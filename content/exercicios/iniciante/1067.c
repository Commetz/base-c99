#include <stdio.h>
 
int main() {
 
    int x;
    scanf("%d", &x);
    
    for(int i = 0; i <= x; i++) {
        if(i % 2 != 0) {
            printf("%d\n", i);
        }
    }
 
    return 0;
}
