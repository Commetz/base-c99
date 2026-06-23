#include <stdio.h>
#include <string.h>

#define MAXP 1000005
#define MAXS 105

int prime[MAXP];

void sieve() {
    for (int i = 2; i < MAXP; i++)
        prime[i] = 1;

    for (int i = 2; i * i < MAXP; i++) {
        if (prime[i]) {
            for (int j = i * i; j < MAXP; j += i)
                prime[j] = 0;
        }
    }
}

int mod_big(char *num, int mod) {
    int r = 0;
    for (int i = 0; num[i]; i++) {
        r = (r * 10 + (num[i] - '0')) % mod;
    }
    return r;
}

int main() {
    sieve();

    char K[MAXS];
    int L;

    while (scanf("%s %d", K, &L) == 2) {
        if (K[0] == '0' && L == 0)
            break;

        int found = 0;

        for (int i = 2; i < L && i < MAXP; i++) {
            if (prime[i]) {
                if (mod_big(K, i) == 0) {
                    printf("BAD %d\n", i);
                    found = 1;
                    break;
                }
            }
        }

        if (!found)
            printf("GOOD\n");
    }

    return 0;
}
