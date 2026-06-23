#include <stdio.h>
#include <string.h>

int main() {

    int a, b; 
    scanf("%d %d", &a, &b);

    for(int i = 0; i < b; i++) {
        char frase[11];
        scanf("%s", frase);

        if(strcmp(frase, "fechou")) {
            a++;
        } else {
            a--;
        }
    }
    
    printf("%d\n", a);
    
    return 0;
}   
