#include <stdio.h>

int main() {

    int x, y; 
    scanf("%d %d", &x, &y);

    int l1 = (x * y) + ((x - 1) * (y - 1));
    int l2 = (2 * (x - 1)) + (2 * (y - 1));

    printf("%d\n%d\n", l1, l2); 
    
    return 0;
}
