#include <stdio.h>

int euclides(int a, int b) {
    while(b != 0) {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    int n, q;

    while (scanf("%d %d", &n, &q) == 2) {
        int s[n];  

        for(int i = 0; i < n; i++) {
            scanf("%d", &s[i]);
        }

        for(int i = 0; i < q; i++) {
            int tipo;
            scanf("%d", &tipo);

            if(tipo == 1) {
                int a, b, v;
                scanf("%d %d %d", &a, &b, &v);
                a--; b--;
                for(int j = a; j <= b; j++) {
                    s[j] += v;
                }

            } else if (tipo == 2) {
                int a, b;
                scanf("%d %d", &a, &b);
                a--; b--;

                int mdc = s[a];
                for(int j = a + 1; j <= b; j++) {
                    mdc = euclides(mdc, s[j]);
                }
                printf("%d\n", mdc);
            }
        }
    }

    return 0;
}

