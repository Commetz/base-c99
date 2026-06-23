#include <stdio.h>

int main() {

    int x; 
    scanf("%d", &x);

    for(int i = 0; i < x; i++) {
        double a, b, c; 
        scanf("%lf %lf %lf", &a, &b, &c);

        printf("%.1lf\n", ((a * 2) + (b * 3) + (c * 5)) / 10); 
    } 
    
    return 0;
}
