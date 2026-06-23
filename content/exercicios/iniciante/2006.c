#include <stdio.h>

int main(){
    
    int t, contador = 0;
    scanf("%d", &t);

    for(int i = 5; i > 0; i--) {
        int x;
        scanf("%d", &x);

        if(x == t) {
            contador++;
        }
    }

    printf("%d\n", contador);
    
    return 0;
}
