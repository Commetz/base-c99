#include <stdio.h>

int main() {
    
    double a, b;
    scanf("%lf %lf", &a, &b);
    
    double c;
    
    c = ((((1 + (a/100)) * (1 + (b/100))) - 1) * 100);
    
    printf("%.6lf\n", c);
    
    return 0;
}

