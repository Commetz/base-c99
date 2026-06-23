#include <stdio.h>

int main() {

    int n;
    
    while(scanf("%d", &n) != EOF) {
        int t[n+1], d[n+1];

        for(int i = 0; i < n; i++) {
            scanf("%d %d", &t[i], &d[i]);
        }   
        
        double record = 0;

        for(int i = 0; i < n; i++) {
            double di = d[i], ti = t[i];
            double atual = di / ti;
            if(atual > record) {
                record = atual;
                printf("%d\n", i+1);
            }
        }
    }
    
    return 0;
}   

