#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);

    int a, matricula = 0;
    double b, maior = 0;

    for(int i = 0; i < n; i++) {
        
        scanf("%d %lf", &a, &b);

        if(b >= 8 && b >= maior) {
            maior = b;
            matricula = a;
        }
    }
    
    if(matricula == 0) {
        printf("Minimum note not reached\n");
    } else {
        printf("%d\n", matricula);
    }
      
    return 0;
}
