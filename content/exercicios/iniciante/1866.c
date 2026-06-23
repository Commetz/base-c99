#include <stdio.h>

int main(){
    
    int n;
    scanf("%d", &n);

    for(int i = n; i > 0; i--) {
        int x;
        scanf("%d", &x);
        
        if(x % 2 == 0) {
            printf("0\n");
        } else {
            printf("1\n");
        }
    }

    return 0;
}
