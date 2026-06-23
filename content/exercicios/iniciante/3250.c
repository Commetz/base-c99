#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int f, s, g, u, d;
    if (scanf("%d %d %d %d %d", &f, &s, &g, &u, &d) != 5) return 0;

    if (s == g) {
        printf("0\n");
        return 0;
    }

    int *dist = (int *)malloc((f + 1) * sizeof(int));
    int *q = (int *)malloc((f + 1) * sizeof(int));

    if (!dist || !q) return 0;

    for (int i = 1; i <= f; i++) dist[i] = -1;

    int head = 0, tail = 0;
    q[tail++] = s;
    dist[s] = 0;

    while (head < tail) {
        int cur = q[head++];

        if (u > 0) {
            int nxt = cur + u;
            if (nxt <= f && dist[nxt] == -1) {
                dist[nxt] = dist[cur] + 1;
                if (nxt == g) {
                    printf("%d\n", dist[nxt]);
                    free(dist);
                    free(q);
                    return 0;
                }
                q[tail++] = nxt;
            }
        }

        if (d > 0) {
            int nxt = cur - d;
            if (nxt >= 1 && dist[nxt] == -1) {
                dist[nxt] = dist[cur] + 1;
                if (nxt == g) {
                    printf("%d\n", dist[nxt]);
                    free(dist);
                    free(q);
                    return 0;
                }
                q[tail++] = nxt;
            }
        }
    }

    printf("use the stairs\n");

    free(dist);
    free(q);
    return 0;
}
