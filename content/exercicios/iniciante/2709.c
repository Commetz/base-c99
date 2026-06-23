#include <stdio.h>

int eh_primo(long long n) {
    if (n < 2)
        return 0;

    if (n == 2)
        return 1;

    if (n % 2 == 0)
        return 0;

    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

int main() {

    int n;
    
    while(scanf("%d", &n) != EOF) {
        int x[n];

        for(int i = 0; i < n; i++) {
            scanf("%d", &x[i]);
        }

        int m, soma = 0;
        scanf("%d", &m);
        
        for(int i = n-1; i >= 0;) {
            soma += x[i];
            i -= m;
        }
        
        if(eh_primo(soma) == 1) {
            printf("You’re a coastal aircraft, Robbie, a large silver aircraft.\n");
        } else {
            printf("Bad boy! I’ll hit you.\n");
        }

    }   
    
    return 0;
}
