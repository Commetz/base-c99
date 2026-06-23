#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);

    double total = 0;

    for(int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        if(a == 1001) {
            double c = 1.5 * b;
            total += c;
        } else if(a == 1002) {
            double c = 2.5 * b;
            total += c;
        } else if(a == 1003) {
            double c = 3.5 * b;
            total += c;
        } else if(a == 1004) {
            double c = 4.5 * b;
            total += c;
        } else if(a == 1005) {
            double c = 5.5 * b;
            total += c;
        }
    }
    
    printf("%.2lf\n", total);
    
    return 0;
}
