#include <stdio.h>
#include <stdlib.h>

int main() {

    int i, j;
    
    while(scanf("%d %d", &i, &j) != EOF) {
        int m[i+1][j+1], x1, y1, x2, y2;

        for(int k = 1; k <= i; k++) {
            for(int l = 1; l <= j; l++) {
                scanf("%d", &m[k][l]);
            }
        }
            
        for(int k = 1; k <= i; k++) {
            for(int l = 1; l <= j; l++) {
                if(m[k][l] == 2) {
                    x1 = k;
                    y1 = l;
                } else if(m[k][l] == 1) {
                    x2 = k;
                    y2 = l;
                }
            }
        }

        printf("%d\n", abs(x1 - x2) + abs(y1 - y2));

    }

    return 0;
}   
