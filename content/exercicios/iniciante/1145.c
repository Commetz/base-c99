#include <stdio.h>

int main() {

    int x, y;
    scanf("%d %d", &x, &y);
    
    for(int i = 1; i < y;) {
        printf("%d", i);
        i++;
        for(int j = 1; j < x; j++) {
            printf(" %d", i);
            i++;
        }
        printf("\n");
    }

    return 0;
}
