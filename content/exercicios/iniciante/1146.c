#include <stdio.h> 

int main () {

    int n = 1;

    while(1) {
        int i = 1;
        scanf("%d", &n);
        
        if(n == 0) {
            return 0;
        }

        printf("%d", i);
        i++;

        for(; i <= n;) {
            printf(" %d", i);
            i++;
        }

        printf("\n");
    }

    return 0;
}
