#include <stdio.h>

int main() {

    int n, m, v[301], cont = 0;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < 300; i++) {
        v[i] = 1;
    }
    

    for(int i = 0; i < m; i++) {
        int x;
        scanf("%d", &x);

        if(v[x] == 1) {
            v[x] = 0;
            cont++;
        }
    }
    
    printf("%d\n", n - cont);
    
    return 0;
}
