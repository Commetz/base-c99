#include <stdio.h>

int main() {

    int x; 
    scanf("%d", &x);

    for(int i = 0; i < x; i++) {
        int a, b, cont = 0; 
        scanf("%d %d", &a, &b);

        if(b <= a) {
            int c = a;
            a = b;
            b = c;
        } 

        for(int i = a + 1; i < b; i++) {
            if(i % 2 != 0) {
                cont += i;
            }
        }
        printf("%d\n", cont);
    }   
    
    return 0;
}
