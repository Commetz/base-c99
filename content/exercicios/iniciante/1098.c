#include <stdio.h>

int main () {
    
    double i = 0, j = 1;
    
    for(int m = 3; m > 0; m--) {
        printf("I=%.0lf J=%.0lf\n", i, j);
        j++;
    }

    for(; i <= 0.7;) {
        i += 0.2;
        j -= 2.8;
        for(int k = 3; k > 0; k--) {
            printf("I=%.1lf J=%.1lf\n", i, j);
            j++;
        }
    }
    
    j -= 3;
    
    for(int m = 3; m > 0; m--) {
        printf("I=%.0lf J=%.0lf\n", i, j);
        j++;
    }
    
    i += 0.2;
    j += 0.2;
    
    for(; i <= 1.6;) {
        i += 0.2;
        j -= 2.8;
        for(int k = 3; k > 0; k--) {
            printf("I=%.1lf J=%.1lf\n", i, j);
            j++;
        }
    }
    
    j -= 3;
    
    for(int m = 3; m > 0; m--) {
        printf("I=%.0lf J=%.0lf\n", i, j);
        j++;
    }

    return 0;
}
