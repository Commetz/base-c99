#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);
    
    for(; n > 0; n--) {
        double x, y;
        scanf("%lf %lf", &x, &y);
        
        if(y == 0) {
            printf("divisao impossivel\n");
        } else {
            printf("%.1lf\n", x / y);
        }
    }

    return 0;
}
