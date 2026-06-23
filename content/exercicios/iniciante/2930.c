#include <stdio.h>

int main() {

    int a, b; 
    scanf("%d %d", &a, &b);

    if(b - a >= 3) {
        printf("Muito bem! Apresenta antes do Natal!\n");
    } else if(b - a < 3 && b - a >= 0) {
        printf("Parece o trabalho do meu filho!\n");
        if(b >= 23) {
            printf("Fail! Entao eh nataaaaal!\n");
        } else {
            printf("TCC Apresentado!\n");
        }
    } else {
        printf("Eu odeio a professora!\n");
    }
    
    return 0;
}

