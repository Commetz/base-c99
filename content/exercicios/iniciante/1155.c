#include <stdio.h>

int main() {

    double s = 0;
    
    for(double i = 1; i <= 100;) {
        s += 1 / i;
        i++;
    }

    printf("%.2lf\n", s);

    return 0;
}
