#include <stdio.h>

int main() {

    int i, j;
    scanf("%d %d", &i, &j);

    int m[i][j];

    for(int k = 0; k < i; k++) {
        for(int l = 0; l < j; l++) {
           scanf("%d", &m[k][l]);
        }
    }

    for(int k = 1; k < i - 1; k++) {
        for(int l = 1; l < j - 1; l++) {
           if(m[k][l] == 42 && m[k-1][l-1] == 7 && m[k-1][l] == 7 && m[k-1][l+1] == 7 && m[k][l-1] == 7 && m[k][l+1] == 7 && m[k+1][l-1] == 7 && m[k+1][l] && m[k+1][l+1] == 7) {
                printf("%d %d\n", k, l);
                return 0;
           }
        }
    }

    printf("0 0\n");
    
    return 0;
}   
