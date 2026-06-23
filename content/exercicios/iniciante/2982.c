#include <stdio.h>

int main() {

    int n, contg = 0, contv = 0;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        char x[2];
        int c;
        scanf("%s %d", x, &c);

        if(x[0] == 'V') {
            contv += c;
        } else if(x[0] == 'G') {
            contg += c;
        }
    }

    if(contv >= contg) {
        printf("A greve vai parar.\n");
    } else {
        printf("NAO VAI TER CORTE, VAI TER LUTA!\n");
    }
    
    return 0;
}   

