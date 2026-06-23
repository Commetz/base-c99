#include <stdio.h>

int main() {

    double a, b; 
    scanf("%lf %lf", &a, &b);

    double c = a - b;

    printf("%.2lf%\n", (c * 100) / a);
    
    return 0;
}
