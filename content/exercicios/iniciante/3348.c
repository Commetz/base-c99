#include <stdio.h>

long long mdc(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long mmc(long long a, long long b) {
    return (a / mdc(a, b)) * b;
}

int main() {
    int n;
    scanf("%d", &n);
    
    long long x;
    
    long long resp = n + 1;

    for (int i = n + 2; i <= 2 * n; i++) {
        x = i;
        resp = mmc(resp, x);
    }

    printf("%lld\n", resp);

    return 0;
}
