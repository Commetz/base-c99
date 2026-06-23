#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    long long v[1005];

    for (int i = 0; i < n; i++)
        scanf("%lld", &v[i]);

    if (n <= 2) {
        printf("1\n");
        return 0;
    }

    int escadas = 1;
    long long diff = v[1] - v[0];

    for (int i = 2; i < n; i++) {
        long long ndiff = v[i] - v[i - 1];

        if (ndiff != diff) {
            escadas++;
            diff = ndiff;
        }
    }

    printf("%d\n", escadas);

    return 0;
}
