#include <stdio.h>
#include <string.h>

#define MAXN 205
#define MAXV (MAXN * 2)
#define MAXE 200000

static int n;
static int teacher[MAXN];
static int rankpos[MAXN][MAXN];

static signed char bitmap[3][3] = {
    {-1, 0, 1},  // teacher 0 -> classes 1 or 2
    { 0,-1, 1},  // teacher 1 -> classes 0 or 2
    { 0, 1,-1}   // teacher 2 -> classes 0 or 1
};

static int head[MAXV], to[MAXE], nxt[MAXE], ecnt;
static int rhead[MAXV], rto[MAXE], rnxt[MAXE], recnt;

static int vis[MAXV], order[MAXV], ordsz, comp[MAXV], timer;
static int st[MAXV];

static void add_imp(int u, int v) {
    to[ecnt] = v;
    nxt[ecnt] = head[u];
    head[u] = ecnt++;

    rto[recnt] = u;
    rnxt[recnt] = rhead[v];
    rhead[v] = recnt++;
}

static void add_clause(int a, int b) {
    add_imp(a ^ 1, b);
    add_imp(b ^ 1, a);
}

static void add_forbid(int var1, int val1, int var2, int val2) {
    int l1 = 2 * var1 + (1 - val1);
    int l2 = 2 * var2 + (1 - val2);
    add_clause(l1, l2);
}

static void dfs1(int v) {
    vis[v] = 1;
    for (int e = head[v]; e != -1; e = nxt[e]) {
        int u = to[e];
        if (!vis[u]) dfs1(u);
    }
    order[ordsz++] = v;
}

static void dfs2(int v, int c) {
    comp[v] = c;
    for (int e = rhead[v]; e != -1; e = rnxt[e]) {
        int u = rto[e];
        if (comp[u] == -1) dfs2(u, c);
    }
}

static int check(int T) {
    int V = 2 * n;

    for (int i = 0; i < V; i++) {
        head[i] = rhead[i] = -1;
        vis[i] = 0;
        comp[i] = -1;
    }
    ecnt = recnt = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (rankpos[i][j] <= T && rankpos[j][i] <= T) continue;

            int ti = teacher[i], tj = teacher[j];

            for (int c = 0; c < 3; c++) {
                int bi = bitmap[ti][c];
                int bj = bitmap[tj][c];
                if (bi != -1 && bj != -1) {
                    add_forbid(i - 1, bi, j - 1, bj);
                }
            }
        }
    }

    ordsz = 0;
    for (int i = 0; i < V; i++) {
        if (!vis[i]) dfs1(i);
    }

    int cid = 0;
    for (int i = V - 1; i >= 0; i--) {
        int v = order[i];
        if (comp[v] == -1) {
            dfs2(v, cid++);
        }
    }

    for (int i = 0; i < n; i++) {
        if (comp[2 * i] == comp[2 * i + 1]) return 0;
    }
    return 1;
}

int main(void) {
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 1; i <= n; i++) {
        int t;
        scanf("%d", &t);
        teacher[i] = t;

        for (int j = 1; j <= n - 1; j++) {
            int x;
            scanf("%d", &x);
            rankpos[i][x] = j;
        }
    }

    int lo = 0, hi = n - 1, ans = n - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    printf("%d\n", ans);
    return 0;
}
