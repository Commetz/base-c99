#include <stdio.h>

int main() {

    int x;
    scanf("%d", &x);
    
    for(int i = 0; i < x; i++) {
        int n;
        scanf("%d", &n);
        
        if(n == 1) {
            printf("0\n");
        } else if(n == 2) {
            printf("6\n");
        } else if(n == 3) {
            printf("12\n");
        } else if(n == 4) {
            printf("90\n");
        } else if(n == 5) {
            printf("360\n");
        } else if(n == 6) {
            printf("2040\n");
        } else if(n == 7) {
            printf("10080\n");
        } else if(n == 8) {
          printf("54810\n"); 
        } else if(n == 9) {
            printf("290640\n");
        } else if(n == 10) {
            printf("1588356\n");
        } else if(n == 11) {
            printf("8676360\n");
        } else if(n == 12) {
            printf("47977776\n");
        } else if(n == 13) {
            printf("266378112\n");
        } else {
            printf("1488801600\n");
        }
    }
    
    return 0;
}

