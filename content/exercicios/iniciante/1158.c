#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);
    
    for(; n > 0; n--) {
        int x, y, z = 0;
        scanf("%d %d", &x, &y);
        
        if(x % 2 != 0) {
            for(; y > 0; y--) {
                if(x % 2 != 0) {
                    z += x;
                    x+= 2;
                }
            }
            printf("%d\n", z);
        } else {
            x++;
            for(; y > 0; y--) {
                if(x % 2 != 0) {
                    z += x;
                    x+= 2;
                }
            }
            printf("%d\n", z);
        }
    }

    return 0;
}
