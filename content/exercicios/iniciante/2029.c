#include <stdio.h>
#include <math.h>

int main() {

    double v, d;

    while(scanf("%lf %lf", &v, &d) != EOF) {
        printf("ALTURA = %.2lf\n", (4 * v) / (3.1415 * pow(d, 2)));
        printf("AREA = %.2lf\n", (3.1415 * pow(d, 2)) / 2);
    }
    
    return 0;
}

