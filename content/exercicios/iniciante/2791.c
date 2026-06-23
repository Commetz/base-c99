#include <stdio.h>

int main() {

    int v[5];

    for(int i = 0; i < 4; i++) {
        scanf("%d", &v[i]);
    }
    
    for(int i = 0; i < 4; i++) {
        if(v[i] == 1) {
            printf("%d\n", i + 1);
            break;
        }
    }
    
    return 0;
}   
