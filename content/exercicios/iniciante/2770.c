#include <stdio.h>

int main() {
    int X, Y, M;

    while (scanf("%d %d %d", &X, &Y, &M) == 3) {
        for (int i = 0; i < M; i++) {
            int a, b;
            scanf("%d %d", &a, &b);

            if ((a <= X && b <= Y) ||
                (a <= Y && b <= X))
                printf("Sim\n");
            else
                printf("Nao\n");
        }
    }

    return 0;
}
