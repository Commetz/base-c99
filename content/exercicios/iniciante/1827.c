#include <stdio.h>

int main() {

    int n; 

    while(scanf("%d", &n) != EOF) {
        int m = n / 3;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(j >= m && i >=  m && j < n - m && i < n - m) {
                    if(i == j && j == (n - 1) / 2) {
                        printf("4");
                    } else {
                        printf("1");
                    }
                } else {
                    if(j == i && j != (n - 1) / 2) {
                        printf("2");
                    } else if(i + j == n - 1) {
                        printf("3");
                    } else { 
                        printf("0");
                    }
                }
            }
            printf("\n");
        }
        printf("\n");
    }
        
    return 0;
}   

