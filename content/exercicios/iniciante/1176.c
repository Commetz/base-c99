#include <stdio.h>

int main() {

    long long int x = 0, y = 1;
    long long int a[61];
    
    for(int i = 2; i < 61; i++) {
        long long int z = x + y;

        a[0] = 0;
        a[1] = 1;
        a[i] = z;
        

        x = y;
        y = z;

    }
    
    int t;
    scanf("%d", &t);
    
    for(; t > 0; t--) {
        int s;
        scanf("%d", &s);
        
        printf("Fib(%d) = %lld\n", s, a[s]);
    }
    

    return 0;
}
