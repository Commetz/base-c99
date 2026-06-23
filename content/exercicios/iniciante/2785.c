#include <stdio.h>

#define INF 1000000000

int a[105][105];
int pref[105][105];
int dp[105][105];

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        pref[i][0] = 0;

        for (int j = 1; j <= N; j++) {
            scanf("%d", &a[i][j]);
            pref[i][j] = pref[i][j - 1] + a[i][j];
        }
    }

    /* linha N */
    dp[N][1] = pref[N][N];

    for (int i = N - 1; i >= 1; i--) {

        int maxStart = N - i + 1;

        for (int j = 1; j <= maxStart; j++) {

            int seg =
                pref[i][j + i - 1] -
                pref[i][j - 1];

            int best = INF;

            if (j <= N - (i + 1) + 1)
                if (dp[i + 1][j] < best)
                    best = dp[i + 1][j];

            if (j - 1 >= 1)
                if (dp[i + 1][j - 1] < best)
                    best = dp[i + 1][j - 1];

            dp[i][j] = seg + best;
        }
    }

    int ans = INF;

    for (int j = 1; j <= N; j++) {
        if (dp[1][j] < ans)
            ans = dp[1][j];
    }

    printf("%d\n", ans);

    return 0;
}
