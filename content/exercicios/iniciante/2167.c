#include <stdio.h>

int main() {

    int x, a, b = 0;
    scanf("%d", &x);

    for(int i = 1; i <= x; i++) {
        scanf("%d", &a);

        if(a < b) {
            printf("%d\n", i);
            return 0;
        } else {
            b = a;
        }   
    }

    print("0\n");
    
    return 0;
}
