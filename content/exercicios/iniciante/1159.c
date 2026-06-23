#include <stdio.h>

int main() {

    while(1) {
        int x, z = 0;
        scanf("%d", &x);
        
        if (x == 0) {
            return 0;
        }

        if(x % 2 == 0) {
            for(int i = 5; i > 0; i--) {
                if(x % 2 == 0) {
                    z += x;
                    x+= 2;
                }
            }
            printf("%d\n", z);
        } else {
            x++;
            for(int i = 5; i > 0; i--) {
                if(x % 2 == 0) {
                    z += x;
                    x+= 2;
                }
            }
            printf("%d\n", z);
        }
    }

    return 0;
}
