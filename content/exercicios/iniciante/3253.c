#include <stdio.h>
#include <string.h>

#define MAXN 1000

int adj[MAXN][MAXN], adj_sz[MAXN];
int radj[MAXN][MAXN], radj_sz[MAXN];

int visited[MAXN];
int order[MAXN]; 
int order_sz;
int present[MAXN]; 

void dfs(int u, int graph[][MAXN], int *sz, int *vis) {
    vis[u] = 1;
    for (int i = 0; i < sz[u]; i++) {
        int v = graph[u][i];
        if (!vis[v])
            dfs(v, graph, sz, vis);
    }
}

int main() {
    int streets;
    scanf("%d", &streets);

    memset(adj_sz, 0, sizeof(adj_sz));
    memset(radj_sz, 0, sizeof(radj_sz));
    memset(present, 0, sizeof(present));
    order_sz = 0;

    for (int i = 0; i < streets; i++) {
        int id, count;
        scanf("%d %d", &id, &count);

        present[id] = 1;
        if (id != 0)
            order[order_sz++] = id;

        for (int j = 0; j < count; j++) {
            int dest;
            scanf("%d", &dest);
            adj[id][adj_sz[id]++] = dest;
            radj[dest][radj_sz[dest]++] = id;
        }
    }

    memset(visited, 0, sizeof(visited));
    dfs(0, adj, adj_sz, visited);
    int unreachable[MAXN], ur_sz = 0;
    for (int i = 0; i < order_sz; i++)
        if (!visited[order[i]])
            unreachable[ur_sz++] = order[i];

    memset(visited, 0, sizeof(visited));
    dfs(0, radj, radj_sz, visited);
    int trapped[MAXN], tr_sz = 0;
    for (int i = 0; i < order_sz; i++)
        if (!visited[order[i]])
            trapped[tr_sz++] = order[i];

    if (tr_sz == 0 && ur_sz == 0) {
        printf("NO PROBLEMS\n");
    } else {
        for (int i = 0; i < tr_sz; i++)
            printf("TRAPPED %d\n", trapped[i]);
        for (int i = 0; i < ur_sz; i++)
            printf("UNREACHABLE %d\n", unreachable[i]);
    }

    return 0;
}
