#include <stdio.h>

int main() {

    int n;
    
    while(scanf("%d", &n) != EOF) {
        int m, l;
        scanf("%d %d", &m, &l);

        int b1[m+1][n+1];
        int b2[l+1][n+1];

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                scanf("%d", &b1[i][j]);
            }
        }

        for(int i = 0; i < l; i++) {
            for(int j = 0; j < n; j++) {
                scanf("%d", &b2[i][j]);
            }
        }

        int c1, c2;
        scanf("%d %d", &c1, &c2);

        int y;
        scanf("%d", &y);

        if(b1[c1-1][y-1] > b2[c2-1][y-1]) {
            printf("Marcos\n");
        } else if(b2[c2-1][y-1] > b1[c1-1][y-1]) {
            printf("Leonardo\n");
        } else {
            printf("Empate\n");
        }    
    }

    return 0;
}

