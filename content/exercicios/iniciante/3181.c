#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_YEAR 1948
#define MAX_YEAR 2008
#define MAXN 405

int N, C;                  
int year[MAXN][MAXN];        

int deg_tmp[MAXN];           

int idx_cmp(const void *a, const void *b) {
    const int *pa = a;
    const int *pb = b;
    if (deg_tmp[*pa] != deg_tmp[*pb]) return deg_tmp[*pb] - deg_tmp[*pa];
    return *pa - *pb;
}

int feasible_for_Y(int Y) {
    int deg[MAXN];               
    memset(deg, 0, sizeof(deg));

    static unsigned char adj[MAXN][MAXN]; 
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            adj[i][j] = 0;

    for (int i = 1; i <= N; ++i) {
        for (int j = i+1; j <= N; ++j) {
            if (year[i][j] < Y) {
                adj[i][j] = adj[j][i] = 1;
                deg[i]++; deg[j]++;
            }
        }
    }

    int ord[MAXN];
    for (int i = 1; i <= N; ++i) { ord[i-1] = i; deg_tmp[i] = deg[i]; }
    qsort(ord, N, sizeof(int), idx_cmp);

    int m = 0;
    for (int i = 1; i <= N; ++i) {
        int v = ord[i-1];
        if (deg[v] >= i-1) m = i;
    }

    for (int a = 0; a < m; ++a) {
        for (int b = a+1; b < m; ++b) {
            int u = ord[a], v = ord[b];
            if (!adj[u][v]) return 0;
        }
    }

    for (int a = m; a < N; ++a) {
        for (int b = a+1; b < N; ++b) {
            int u = ord[a], v = ord[b];
            if (adj[u][v]) return 0;
        }
    }
    
    int a_cnt = 0, b_cnt = 0;
    for (int i = 0; i < m; ++i) {
        int v = ord[i];
        if (deg[v] == m-1) a_cnt++;
    }
    for (int i = m; i < N; ++i) {
        int v = ord[i];
        if (deg[v] == m) b_cnt++;
    }

    int minK = m - a_cnt;
    int maxK = m + b_cnt;
    int low = (N + 2) / 3; 
    int high = (2 * N) / 3; 

    if (minK > high || maxK < low) return 0;
    return 1;
}

int main() {
    while (scanf("%d %d", &N, &C) == 2) {
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                year[i][j] = MAX_YEAR;

        for (int k = 0; k < C; ++k) {
            int a, b, y;
            scanf("%d %d %d", &a, &b, &y);
            year[a][b] = year[b][a] = y;
        }

        int answer = -1;
        for (int Y = MIN_YEAR; Y <= MAX_YEAR; ++Y) {
            if (feasible_for_Y(Y)) { answer = Y; break; }
        }

        if (answer < 0 || answer == 1986) printf("Impossible\n");
        else printf("%d\n", answer);
    }

    return 0;
}

