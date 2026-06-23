#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1005       
#define INF 1000000000   

int n;                 
int *children[MAXN];   
int child_cnt[MAXN];    
int child_cap[MAXN];    

int demand[MAXN];      
int capEdge[MAXN];    

void add_child(int p, int v) {
    if (child_cap[p] == 0) {
        child_cap[p] = 4;
        children[p] = malloc(child_cap[p] * sizeof(int));
        if (!children[p]) exit(1);
    }
    if (child_cnt[p] >= child_cap[p]) {
        child_cap[p] *= 2;
        children[p] = realloc(children[p], child_cap[p] * sizeof(int));
        if (!children[p]) exit(1);
    }
    children[p][child_cnt[p]++] = v;
}

int *solve(int u, int *sz_out) {
    int total = 0;
    int *dp_curr = malloc(sizeof(int));
    if (!dp_curr) exit(1);
    dp_curr[0] = 0;  

    for (int i = 0; i < child_cnt[u]; ++i) {
        int v = children[u][i];
        int sz_v;
        int *dp_v = solve(v, &sz_v);

        int new_sz = total + sz_v;
        int *new_dp = malloc((new_sz + 1) * sizeof(int));
        if (!new_dp) exit(1);
        for (int k = 0; k <= new_sz; ++k) new_dp[k] = INF;

        for (int a = 0; a <= total; ++a) {
            if (dp_curr[a] >= INF) continue;
            for (int b = 0; b <= sz_v; ++b) {
                if (dp_v[b] >= INF) continue;
                int val = dp_curr[a] + dp_v[b];
                if (val < new_dp[a + b]) new_dp[a + b] = val;
            }
        }

        free(dp_v);
        free(dp_curr);
        dp_curr = new_dp;
        total = new_sz;
    }

    if (u == 0) { 
        *sz_out = total;
        return dp_curr;
    } else {
        int sz_u = total;
        int *dp_u = malloc((sz_u + 2) * sizeof(int));
        if (!dp_u) exit(1);
        for (int k = 0; k <= sz_u + 1; ++k) dp_u[k] = INF;

        for (int k = 0; k <= sz_u; ++k) {
            if (dp_curr[k] < dp_u[k]) dp_u[k] = dp_curr[k]; 
            int val = dp_curr[k] + demand[u];                
            if (val < dp_u[k + 1]) dp_u[k + 1] = val;
        }

        free(dp_curr);
        ++sz_u; 

        for (int k = 0; k <= sz_u; ++k) {
            if (dp_u[k] > capEdge[u]) dp_u[k] = INF;
        }
        *sz_out = sz_u;
        return dp_u;
    }
}

int main() {
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i <= n; ++i) {
        children[i] = NULL;
        child_cnt[i] = 0;
        child_cap[i] = 0;
        demand[i] = 0;
        capEdge[i] = INF;
    }

    for (int i = 1; i <= n; ++i) {
        int p, r, c;
        scanf("%d %d %d", &p, &r, &c);
        demand[i] = r;
        capEdge[i] = c;
        add_child(p, i);
    }

    int sz_root;
    int *dp_root = solve(0, &sz_root);

    int answer = 0;
    for (int k = 0; k <= sz_root; ++k) {
        if (dp_root[k] < INF) answer = k > answer ? k : answer;
    }

    printf("%d\n", answer);

    free(dp_root);
    for (int i = 0; i <= n; ++i) {
        if (children[i]) free(children[i]);
    }
    return 0;
}

