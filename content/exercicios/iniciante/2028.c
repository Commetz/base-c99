#include <stdio.h>

int main() {

    int n, caso = 1;

    while(scanf("%d", &n) != EOF) {

        int total = 1;

        for(int i = 1; i <= n; i++) {
            total += i;
        }

        if(total == 1) {
            printf("Caso %d: %d numero\n", caso, total);
        } else {
            printf("Caso %d: %d numeros\n", caso, total);
        }

        printf("0");

        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < i; j++) {
                printf(" %d", i);
            }
        }

        printf("\n\n");

        caso++;
    }

    return 0;
}

