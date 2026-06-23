#include <stdio.h>

int main() {

    double x;
    int y = 0;
    
    for(int i = 100; i > 0; i--) {
        scanf("%lf", &x);
        
        if(x <= 10) {
            printf("A[%d] = %.1lf\n", y, x);
        }
        
        y++;
    }

    return 0;
}
