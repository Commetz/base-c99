#include <stdio.h>

int main() {

    int x, y, z = 0;
    scanf("%d %d", &x, &y);
    
    if(x > y) {
        for(; y <= x; y++) {
            if(y % 13 != 0) {
                z += y;
            }
        }
    }
    else if(y > x) {
        for(; x <= y; x++) {
            if(x % 13 != 0) {
                z += x;
            }
        }
    } else {
        if(x % 13 != 0) {
            z+= x;
        }
    }

    printf("%d\n", z);

    return 0;
}
