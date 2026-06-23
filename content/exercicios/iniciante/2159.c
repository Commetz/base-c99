#include <stdio.h>
#include <math.h>

int main() {

    int n;
    scanf("%d", &n);

    double p = n / log(n);
    double m = 1.25506 * (n / log(n));

    printf("%.1lf %.1lf\n", p, m);
    
    return 0;
}
