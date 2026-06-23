#include <stdio.h>
#include <string.h>

int main() {

    char n[11];
    
    scanf("%s", n);
    
    int t = strlen(n);
    
    for(int i = t - 1; i >= 0; i--) {
        printf("%c", n[i]);
    }
    
    printf("\n");
        
    return 0;
}   

