#include <stdio.h>

int main() {

    int n, m, cont = 0;
    scanf("%d %d", &n, &m);

    char x[n+1]; 
    int y[n+1];

    for(int i = 0; i < n; i++) {
        scanf(" %c %d", &x[i], &y[i]);
    }
    
    int v;
    scanf("%d", &v);

    for(int i = 0; i < v; i++) {
        char g;
        scanf(" %c", &g);

        for(int j = 0; j < n; j++) {
            if(g == x[j]) {
                cont += y[j];
                break;
            }
        }
    }
    
    if(cont >= m) {
        printf("%d\nYou shall pass!\n", cont);
    } else {
        printf("%d\nMy precioooous\n", cont);
    }
    
    return 0;
}


