#include <stdio.h>

int main() {
    
    int x, y = 0, z;

    for(int i = 10; i > 0; i--) {
        scanf("%d", &x);
        
        if(x < 1) {
            z = 1;
        } else {
            z = x;
        }

        printf("X[%d] = %d\n", y, z);

        y++;
        
    }

    return 0;
}
