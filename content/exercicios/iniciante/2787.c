#include <stdio.h>

int main() {

    int x, y; 
    scanf("%d %d", &x, &y);

    if((x + y) % 2 != 0) {
        printf("0\n");
    } else {
        printf("1\n");
    }
    
    return 0;
}
