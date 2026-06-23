#include <stdio.h>

int main() {

    int n;
    
    while(scanf("%d", &n) != EOF) {
        int x, y, cont = 0;
        scanf("%d %d", &x, &y);

        for(int i = 0; i < n; i++) {
            int a;
            scanf("%d", &a);

            if(a >= x && a <= y) {
                cont++;
            }
        }
     
        printf("%d\n", cont);

    }
    
    return 0;
}   
