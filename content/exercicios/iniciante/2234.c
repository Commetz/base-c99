#include <stdio.h>

int main() {
    
    double h, p;
    scanf("%lf %lf", &h, &p);
    
    double n = h / p;
    
    printf("%.2lf\n", n);
    
    return 0;
}
