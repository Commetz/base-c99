#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        char nome[101];
        scanf("%s", nome);
        
        double x;
        scanf("%lf", &x);

        double menor = 11, maior = -1, total = 0;

        for(int i = 0; i < 7; i++) {
            double y;
            scanf("%lf", &y);

            if(y < menor) {
                menor = y;
            }

            if(y > maior) {
                maior = y;
            }

            total += y;
        }
        
        total -= maior + menor;
        total = total * x;

        printf("%s %.2lf\n", nome, total);
        
    }
    
    
    return 0;
}   

