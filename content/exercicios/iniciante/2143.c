#include <stdio.h>

int main() {

    while(1) {
        int t;
        scanf("%d", &t);

        if(t == 0) {
            return 0;
        } 

        for(int i = 0; i < t; i++) {
            int x;
            scanf("%d", &x);
            
            if(x % 2 == 1) {
                printf("%d\n", (x * 2) - 1);
            } else {
                printf("%d\n", (x * 2) - 2);
            }
        }
        
    }    
}
