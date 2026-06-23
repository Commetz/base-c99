#include <stdio.h>

int main() {

    int x, y;

    while(scanf("%d %d", &x, &y) != EOF) {
        int cont = 0;

        for(int i = 0; i < x; i++) {
            int n, m;
            scanf("%d %d", &n, &m);

            if(n == y && m == 0) {
                cont++;
            }
        }
        printf("%d\n", cont);
    }
    
    return 0;
}
