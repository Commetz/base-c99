#include <stdio.h>
#include <string.h>
#include <limits.h>

#define INF 1000000000

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int M;

    while (scanf("%d", &M) == 1 && M) {

        int dp[2][3];
        int cur = 0, prev = 1;

        for (int i = 0; i < 3; i++) {
            dp[prev][i] = INF;
        }

        // começa na pista do meio (índice 1)
        dp[prev][1] = 0;

        for (int i = 0; i < M; i++) {
            int L, C, R;
            scanf("%d %d %d", &L, &C, &R);

            int obs[3] = {L, C, R};

            for (int j = 0; j < 3; j++) {
                dp[cur][j] = INF;

                if (obs[j]) continue; // tem árvore

                for (int k = 0; k < 3; k++) {
                    if (dp[prev][k] == INF) continue;

                    int cost = dp[prev][k] + (k > j ? k - j : j - k);
                    dp[cur][j] = min(dp[cur][j], cost);
                }
            }

            cur ^= 1;
            prev ^= 1;
        }

        int ans = INF;
        for (int i = 0; i < 3; i++)
            ans = min(ans, dp[prev][i]);

        printf("%d\n", ans);
    }

    return 0;
}
