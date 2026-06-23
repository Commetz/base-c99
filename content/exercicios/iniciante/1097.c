#include <stdio.h>

int main () {
    
    int i = 1, j = 7;

    for(; i <= 9;) {
        for(int k = 3; k > 0; k--) {
            printf("I=%d J=%d\n", i, j);
            j--;
        }
        i += 2;
        j += 5;
    }

    return 0;
}
