#include <stdio.h>

int main() {
    int n;

    while (scanf("%d", &n) == 1) {
        int p[1000];
        long long t[1000];

        for (int i = 0; i < n; i++)
            scanf("%d", &p[i]);

        for (int i = 0; i < n; i++)
            scanf("%lld", &t[i]);

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (p[i] > p[j]) {
                    ans += t[i] + t[j];
                }
            }
        }

        printf("%lld\n", ans);
    }

    return 0;
}
