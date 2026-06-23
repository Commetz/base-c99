#include <stdio.h>

int main() {

    int m;
    
    while(scanf("%d", &m) != EOF) {
        int n[m+1], c[m+1];

        double totalc = 0.0, totalb = 0.0;

        for(int i = 0; i < m; i++) {
            scanf("%d %d", &n[i], &c[i]);
        }
                
        for(int i = 0; i < m; i++) {
            totalc += n[i] * c[i];
            totalb += c[i];
        }

        totalb *= 100.0;

        printf("%.4lf\n", totalc/totalb);
        
    }
 
    return 0;
}
