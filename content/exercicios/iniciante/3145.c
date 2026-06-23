#include <stdio.h>

int main() {
    
    double n, x;
    scanf("%lf %lf", &n, &x);
    
    double ans = x / (n + 2);

    printf("%.2lf\n", ans);

    return 0;
}

