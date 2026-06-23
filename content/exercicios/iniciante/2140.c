#include <stdio.h>

int main() {

    int n, m;

    while(n != 0 && m != 0) {
        scanf("%d %d", &n, &m);

        int x = m - n;

        if(x == 200 || x == 150 || x == 120 || x == 110 || x == 105 || x == 102 || x == 100 || x == 70 || x == 60 || x == 55 || x == 52 || x == 40 || x == 30 || x == 25 || x == 22 || x == 20 || x == 15 || x == 12 || x == 10 || x == 7 || x == 4) {
            printf("possible\n");
        } else {
            if(n == 0 && m == 0) {
                return 0;
            } 
            
            printf("impossible\n");
        }
    }   
    
    return 0;
}

