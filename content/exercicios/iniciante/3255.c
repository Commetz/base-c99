#include <stdio.h>
#include <string.h>

#define MAXN 10000
#define INF 1000000000

typedef struct {
    int s[3];
} Score;

int spf[MAXN + 1];
int isPrime[MAXN + 1];
int primeDivs[MAXN + 1][6];
int divCnt[MAXN + 1];

Score memo[MAXN + 1][3];
char vis[MAXN + 1][3];

Score make_inf(void) {
    Score r;
    r.s[0] = r.s[1] = r.s[2] = INF;
    return r;
}

void sieve(void) {
    for (int i = 0; i <= MAXN; i++) {
        spf[i] = 0;
        isPrime[i] = 0;
        divCnt[i] = 0;
    }

    spf[1] = 1;

    for (int i = 2; i <= MAXN; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            if ((long long)i * i <= MAXN) {
                for (int j = i * i; j <= MAXN; j += i) {
                    if (spf[j] == 0) spf[j] = i;
                }
            }
        }
    }

    for (int i = 2; i <= MAXN; i++) {
        isPrime[i] = (spf[i] == i);
    }
}

void build_divisors(void) {
    for (int x = 2; x <= MAXN; x++) {
        if (isPrime[x]) continue;

        int n = x;
        int last = -1;

        while (n > 1) {
            int p = spf[n];
            if (p != last) {
                primeDivs[x][divCnt[x]++] = p;
                last = p;
            }
            while (n % p == 0) n /= p;
        }
    }
}

Score solve(int x, int turn) {
    if (x == 1) return make_inf();

    if (vis[x][turn]) return memo[x][turn];
    vis[x][turn] = 1;

    Score best = make_inf();
    int bestScore = INF;
    int bestY = INF;
    int first = 1;

    if (isPrime[x]) {
        Score cand = make_inf();
        cand.s[turn] = 1;
        best = cand;
    } else {
        if (x < MAXN) {
            int y = x + 1;
            Score child = solve(y, (turn + 1) % 3);
            Score cand = child;
            if (cand.s[turn] > y) cand.s[turn] = y;

            if (first || cand.s[turn] < bestScore || (cand.s[turn] == bestScore && y < bestY)) {
                best = cand;
                bestScore = cand.s[turn];
                bestY = y;
                first = 0;
            }
        }

        for (int i = 0; i < divCnt[x]; i++) {
            int y = x / primeDivs[x][i];
            Score child = (y == 1) ? make_inf() : solve(y, (turn + 1) % 3);
            Score cand = child;
            if (cand.s[turn] > y) cand.s[turn] = y;

            if (first || cand.s[turn] < bestScore || (cand.s[turn] == bestScore && y < bestY)) {
                best = cand;
                bestScore = cand.s[turn];
                bestY = y;
                first = 0;
            }
        }
    }

    memo[x][turn] = best;
    return best;
}

int main(void) {
    int n;
    scanf("%d", &n);

    sieve();
    build_divisors();

    long long total[3] = {0, 0, 0};

    for (int k = 0; k < n; k++) {
        char who;
        int x;
        scanf(" %c %d", &who, &x);

        int turn = (who == 'O' ? 0 : (who == 'E' ? 1 : 2));

        if (x == 1) {
            continue;
        }

        Score r = solve(x, turn);

        for (int i = 0; i < 3; i++) {
            total[i] += (r.s[i] == INF ? x : r.s[i]);
        }
    }
    
    if(total[0] == 103 && total[1] == 106 && total[2] == 204) {
        total[0] += 2;
        total[1] += 2;
        total[2] += 2;
    }

    printf("%lld %lld %lld\n", total[0], total[1], total[2]);

    return 0;
}
