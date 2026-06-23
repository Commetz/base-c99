#include <stdio.h>

#define MAXN 1005

long long a1[MAXN], a2[MAXN];
long long t1[MAXN], t2[MAXN];

int main() {
    int n;

    while (scanf("%d", &n) == 1) {
        long long e1, e2, x1, x2;

        scanf("%lld %lld", &e1, &e2);

        for (int i = 0; i < n; i++)
            scanf("%lld", &a1[i]);

        for (int i = 0; i < n; i++)
            scanf("%lld", &a2[i]);

        for (int i = 0; i < n - 1; i++)
            scanf("%lld", &t1[i]);

        for (int i = 0; i < n - 1; i++)
            scanf("%lld", &t2[i]);

        scanf("%lld %lld", &x1, &x2);

        long long dp1 = e1 + a1[0];
        long long dp2 = e2 + a2[0];

        for (int i = 1; i < n; i++) {
            long long ndp1 = dp1 + a1[i];
            long long alt1 = dp2 + t2[i - 1] + a1[i];

            long long ndp2 = dp2 + a2[i];
            long long alt2 = dp1 + t1[i - 1] + a2[i];

            if (alt1 < ndp1) ndp1 = alt1;
            if (alt2 < ndp2) ndp2 = alt2;

            dp1 = ndp1;
            dp2 = ndp2;
        }

        long long ans1 = dp1 + x1;
        long long ans2 = dp2 + x2;

        printf("%lld\n", ans1 < ans2 ? ans1 : ans2);
    }

    return 0;
}
