#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int x, y, z; 
        scanf("%d %d %d", &x, &y, &z);

        if(x < 10) {
            printf("0%d:", x);
        } else {
            printf("%d:", x);
        }

        if(y < 10) {
            printf("0%d - ", y);
        } else {
            printf("%d - ", y);
        }

        if(z == 1) {
            printf("A porta abriu!\n");
        } else {
            printf("A porta fechou!\n");
        }
    }
    
    return 0;
}
