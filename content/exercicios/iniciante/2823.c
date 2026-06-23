#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    double utilizacao = 0.0;

    for (int i = 0; i < N; i++) {
        int C, P;
        scanf("%d %d", &C, &P);

        utilizacao += (double)C / P;
    }

    if (utilizacao <= 1.0 + 1e-12)
        printf("OK\n");
    else
        printf("FAIL\n");

    return 0;
}
