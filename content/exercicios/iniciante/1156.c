#include <stdio.h>

int main() {

    double s = 0, j = 1;

    for(double i = 1; i <= 39;) {
        s += i / j;
        i += 2;
        j *= 2;
    }

    printf("%.2lf\n", s);

    return 0;
}
