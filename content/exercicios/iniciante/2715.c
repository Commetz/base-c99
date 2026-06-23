#include <stdio.h>

int main() {

    int n;
    
    while(scanf("%d", &n) != EOF) {
        unsigned long long x[n];
        
        for(int i = 0; i < n; i++) {
            scanf("%llu", &x[i]);
        }
        
        
        unsigned long long score1 = 0, score2 = 0;
        int cont = 0;
        
        int j = n-1, i = 0;

        while(1) {
            if(score1 < score2) {
                score1 += x[i];
                i++;
                cont++;
            } else if(score2 <= score1) {
                score2 += x[j];
                j--;
                cont++;
            } 
            
            if(cont == n) {
                break;
            }
        }

        if(score1 > score2) {
            printf("%llu\n", score1 - score2);
        } else {
            printf("%llu\n", score2 - score1);
        }
            
    }

    return 0;
}
