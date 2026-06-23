#include <stdio.h>

int main() {

    int a;
    long long b;

    scanf("%d %lld", &a, &b);

    while(a != 0 && b != 0) {
        printf("%lld\n", a * b);

        scanf("%d %lld", &a, &b);
    } 
    
    return 0;
}
