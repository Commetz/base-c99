#include <stdio.h>

int main() {

    int x, y; 
    
    while(scanf("%d %d", &x, &y) != EOF) {
        int m[y+1][x+1], sin1 = 0, sin2 = 0;

        for(int i = 0; i < y; i++) {
            int sin0 = 0;            
            char data[101];
            scanf("%s", data);

            for(int j = 0; j < x; j++) {
                scanf("%d", &m[i][j]);    
                if(m[i][j] == 0) {
                    sin0 = 1;
                }
            }

            if(sin0 == 0 && sin2 == 0) {
                printf("%s\n", data);
                sin1 = 1;
                sin2 = 1;
            }
        }
        
        sin2 = 0;

        if(sin1 != 1) {
            printf("Pizza antes de FdI\n");
            sin1 = 0;
        } 
    }
    
    return 0;
}

