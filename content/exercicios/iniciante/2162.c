#include <stdio.h>

int main() {

    int n, maior = 2, menor = 2;
    scanf("%d", &n);

    int v[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    if(v[0] > v[1]) {
        maior = 1;
        menor = 0;
    } else if(v[0] < v[1]) {
        menor = 1;
        maior = 0;
    } else {
        printf("0\n");
        return 0;
    }
    
    for(int i = 1; i < n - 1; i++) {
        if(maior == 1) {
            if(v[i] < v[i+1]) {
                maior = 0;
                menor = 1;
            } else {
                printf("0\n");
                return 0;
            }
        } else if(menor == 1) {
            if(v[i] > v[i+1]) {
                menor = 0;
                maior = 1;
            } else {
                printf("0\n");
                return 0;
            }
        }
    }
    
    printf("1\n");
    
    return 0;
}

