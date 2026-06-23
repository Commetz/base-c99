#include <stdio.h>

int main() {

    int n, v[100000];
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &v[i]);

        if(v[i] > v[0]) {
            printf("N\n");
            return 0;
        }
    }
    
    printf("S\n");
    
    return 0;
}
