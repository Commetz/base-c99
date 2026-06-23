#include <stdio.h>
#include <math.h>

int main() {

    long long v, n;
    scanf("%lld %lld", &v, &n);

    long long x = n * v;

    printf("%.0lf", ceil((x * 10.00) / 100.00));

    for(int i = 20; i <= 90; i+=10) {
        long double y = ceil((x * i) / 100.00);
        printf(" %.0Lf", y);
    }

    printf("\n");
    
    return 0;
}   

