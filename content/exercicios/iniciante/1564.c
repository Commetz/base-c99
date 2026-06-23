#include <stdio.h>

int main(){
    int A;

    while(scanf("%d", &A) != EOF){
        if(A == 0) {
            printf("vai ter copa!\n");
        } else {
            printf("vai ter duas!\n");
        }
    }

    return 0;
}
