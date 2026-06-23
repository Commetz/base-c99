#include <stdio.h>
#include <string.h>

int main() {

    char t[501];
    fgets(t, 501, stdin);

    int tamanho = strlen(t);
    
    if(tamanho - 1 > 80) {
        printf("NO\n");
    } else {
        printf("YES\n");
    }
    
    return 0;
}



