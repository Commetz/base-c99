#include <stdio.h>

int main() {

    int x, y; 
    
    while(scanf("%d %d", &x, &y) != EOF) {

        int m[x][y];

        for(int i = 0; i < x; i++) {
            for(int j = 0; j < y; j++) {
                scanf("%d", &m[i][j]);
                
                if(m[i][j] == 1) {
                    m[i][j] = 9;
                }
            }
        }
    
        for(int i = 0; i < x; i++) {
            for(int j = 0; j < y; j++) {
                if(m[i][j] == 9) {
                
                    if(i - 1 != -1 && m[i-1][j] != 9) {
                        m[i-1][j] += 1;
                    }

                    if(j - 1 != -1 && m[i][j-1] != 9) {
                        m[i][j-1] += 1;
                    }

                    if(i + 1 != x && m[i+1][j] != 9) {
                        m[i+1][j] += 1;
                    } 

                    if(j + 1 != y && m[i][j+1] != 9) {
                        m[i][j+1] += 1;
                    }
                } 
            }
        }

        for(int i = 0; i < x; i++) {
            for(int j = 0; j < y; j++) {
                printf("%d", m[i][j]);
            }
            printf("\n");
        }
    }
    
    return 0;
}      

