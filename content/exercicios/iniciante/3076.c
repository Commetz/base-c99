#include <stdio.h>
#include <math.h>

int main() {
    
    long long n;
    
    while(scanf("%lld", &n) != EOF) {
        int j = ceil(n / 100.00);
    
        printf("%d\n", j);
    }
    
    return 0;
}
