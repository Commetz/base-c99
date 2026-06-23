#include <stdio.h>

int main() {

    int n;
    while(scanf("%d", &n) != EOF) {
        double yes = 0;

        for(int i = 0; i < n; i++) {
            int m;
            scanf("%d", &m);

            if(m == 1) {
                yes++;
            } 
        }
        
        double why = ((n * 2.0) / 3.0);
        
        if(yes >= why) {
            printf("impeachment\n");
        } else {
            printf("acusacao arquivada\n");
        }
    }
    
    return 0;
}   

