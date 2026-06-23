#include <stdio.h>

int main() {

    int t;
    scanf("%d", &t);
    
    for(int i = 0; i < 1000;) {
        for(int j = 0; j < t; j++, i++) {
            if(i >= 1000) {
                break;
            }
            printf("N[%d] = %d\n", i, j);
        }
    }

    return 0;
}
