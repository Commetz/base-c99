#include <stdio.h>

int main() {

    int a, b; 
    
    while(scanf("%d %d", &a, &b) != EOF) {
        if(b > a) {
            printf("ok\n");
        } else {
            printf("no\n");
        }
    }
    
    return 0;
}
