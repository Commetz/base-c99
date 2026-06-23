#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int a; 
        scanf("%d", &a);

        if(a >= 2015) {
            printf("%d A.C.\n", a - 2014);
        } else {
            printf("%d D.C.\n", 2015 - a);
        }
    }
    
    
    return 0;
}
