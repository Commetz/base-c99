#include <stdio.h>
#include <string.h>

#define MAXN 1005
#define MAXE 20005
#define INF -1

int head[MAXN], to[MAXE], nxt[MAXE], ecnt;
int dist[MAXN];
int queue[MAXN];

void add_edge(int a, int b) {
    to[ecnt] = b;
    nxt[ecnt] = head[a];
    head[a] = ecnt++;
}

void bfs(int n) {
    int front = 0, back = 0;

    for (int i = 0; i < n; i++) {
        if (dist[i] == 0) {
            queue[back++] = i;
        }
    }

    while (front < back) {
        int u = queue[front++];

        for (int e = head[u]; e != -1; e = nxt[e]) {
            int v = to[e];

            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                queue[back++] = v;
            }
        }
    }
}

int main() {
    int N, H, L;
    scanf("%d %d %d", &N, &H, &L);

    memset(head, -1, sizeof(head));
    ecnt = 0;

    for (int i = 0; i < N; i++) dist[i] = -1;

    for (int i = 0; i < H; i++) {
        int x;
        scanf("%d", &x);
        dist[x] = 0;
    }

    for (int i = 0; i < L; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        add_edge(a, b);
        add_edge(b, a);
    }

    bfs(N);

    int best = -1;

    // se existe infinito (não alcançável de horror)
    for (int i = 0; i < N; i++) {
        if (dist[i] == -1) {
            if (best == -1 || i < best) best = i;
        }
    }

    // se não existe infinito, pega maior dist
    if (best == -1) {
        int maxd = -1;
        for (int i = 0; i < N; i++) {
            if (dist[i] > maxd) {
                maxd = dist[i];
                best = i;
            } else if (dist[i] == maxd && i < best) {
                best = i;
            }
        }
    }

    printf("%d\n", best);

    return 0;
}
