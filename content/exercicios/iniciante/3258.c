#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1000
#define MAXK 500
#define MAXE (MAXN * MAXK * 2)

typedef struct {
    long long num, den;   // valor = num / den
    int item;
    unsigned char type;   // 0 = início, 1 = fim
} Event;

static long long W[MAXN];
static int cnt[MAXN];
static Event *ev;

static long long gcdll(long long a, long long b) {
    while (b) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

static int cmpEvent(const void *A, const void *B) {
    const Event *a = (const Event *)A;
    const Event *b = (const Event *)B;

    long long left = a->num * b->den;
    long long right = b->num * a->den;

    if (left < right) return -1;
    if (left > right) return 1;

    if (a->type != b->type) return (int)a->type - (int)b->type;
    return a->item - b->item;
}

int main(void) {
    int N;
    int whole, frac;
    long long p; // T' = p / 10000

    if (scanf("%d.%d %d", &whole, &frac, &N) != 3) return 0;
    p = (long long)whole * 10000LL + (long long)frac * 100LL + 1LL; // T + 0.0001

    for (int i = 0; i < N; i++) scanf("%lld", &W[i]);

    ev = (Event *)malloc(sizeof(Event) * MAXE);
    if (!ev) return 0;

    int m = 0;
    for (int i = 0; i < N; i++) {
        for (int k = 1; k <= MAXK; k++) {
            // início: W / k
            long long n1 = W[i], d1 = k;
            long long g = gcdll(n1, d1);
            n1 /= g; d1 /= g;
            ev[m++] = (Event){ n1, d1, i, 0 };

            // fim: W / (k * T') = W * 10000 / (k * p)
            long long n2 = W[i] * 10000LL, d2 = (long long)k * p;
            g = gcdll(n2, d2);
            n2 /= g; d2 /= g;
            ev[m++] = (Event){ n2, d2, i, 1 };
        }
    }

    qsort(ev, m, sizeof(Event), cmpEvent);

    long long activeItems = 0;
    long long bestNum = 0, bestDen = 1;
    int found = 0;

    memset(cnt, 0, sizeof(cnt));

    for (int i = 0; i < m; ) {
        int j = i;

        // mesmo ponto (num/den) — os eventos de início vêm antes dos de fim
        while (j < m && ev[j].num == ev[i].num && ev[j].den == ev[i].den && ev[j].type == 0) {
            int id = ev[j].item;
            if (cnt[id] == 0) activeItems++;
            cnt[id]++;
            j++;
        }

        if (activeItems == N) {
            bestNum = ev[i].num;
            bestDen = ev[i].den;
            found = 1;
        }

        while (j < m && ev[j].num == ev[i].num && ev[j].den == ev[i].den) {
            int id = ev[j].item;
            cnt[id]--;
            if (cnt[id] == 0) activeItems--;
            j++;
        }

        i = j;
    }

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        long long pieces = (W[i] * bestDen + bestNum - 1) / bestNum; // ceil(W / x)
        ans += pieces - 1;
    }

    printf("%lld\n", ans);

    free(ev);
    return 0;
}
