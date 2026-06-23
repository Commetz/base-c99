#include <stdio.h>

int main() {

    int n, x[30];
    scanf("%d", &n);

    x[0] = 1;
    x[1] = 1;

    for(int i = 2; i < 25; i++) {
        x[i] = x[i - 1] + x[i - 2];
    }

    for(int i = 2; n > 0; i++) {
        if(x[i-1] - x[i-2] > 1) {
            for(int j = x[i-2] + 1; j < x[i-1]; j++) {
                if(n == 1) {
                    printf("%d\n", j);
                }
                n--;
            }     
        } 
    }
    
    return 0;
}

