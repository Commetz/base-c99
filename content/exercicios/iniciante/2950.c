#include <stdio.h>

int main() {

    double n, x, y; 
    scanf("%lf %lf %lf", &n, &x, &y);

    double a = n / (x + y);

    printf("%.2lf\n", a);
    
    return 0;
}
