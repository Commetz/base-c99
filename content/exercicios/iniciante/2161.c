#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);

    double m = 0.0;

    for(int i = 0; i < n; i++) {
        m += 6;
        m = 1.0 / m;
    }
    
    printf("%.10lf\n", m + 3);
    
    return 0;
}
