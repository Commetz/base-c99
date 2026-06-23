#include <stdio.h>

int main() {

    int a, b, c, v[301], cont = 0;
    scanf("%d %d %d", &a, &b, &c);

    for(int i = 0; i < 300; i++) {
        v[i] = 1;
    }
    

    for(int i = 0; i < b; i++) {
        int x; 
        scanf("%d", &x);

        v[x] = 0; 
    }
     
    for(int i = 0; i < c; i++) {
        int x; 
        scanf("%d", &x);
 
        if(v[x] == 0) {
            v[x] = 1;

            cont++;
        }
    }
   
    printf("%d\n", b - cont);
    
    return 0;
}
