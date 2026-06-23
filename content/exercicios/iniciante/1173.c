#include <stdio.h>

int main() {

    int x, y = 0, z;
    scanf("%d", &x);
    z = x;

    for(int i = 10; i > 0; i--) {
        printf("N[%d] = %d\n", y, z);
        z *= 2;
        y++;
    }

    return 0;
}
