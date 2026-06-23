#include <stdio.h>
#include <math.h>

int main() {

    double h, m; 
    
    while(scanf("%lf %lf", &h, &m) != EOF) {

        h = 60.0 * h;
    
        int qt = h / m;
    
        double x[qt + 1], cont = 0, ans = 0;
    
        for(int i = 0; i < qt; i++) {
            scanf("%lf", &x[i]);
    
            cont += x[i];
        }
        
        double media = cont / qt;
    
        for(int i = 0; i < qt; i++) {
            ans += pow((x[i] - media), 2) / (qt - 1);
        }
        
        printf("%.5lf\n", sqrt(ans));
    }
        
    return 0;
}   
    
