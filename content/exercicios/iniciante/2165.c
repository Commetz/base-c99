#include <stdio.h>
#include <string.h>

int main() {

    char t[501];
    fgets(t, 501, stdin);

    int tamanho = strlen(t);
    
    if(tamanho - 1 > 140) {
        printf("MUTE\n");
    } else {
        printf("TWEET\n");
    }
    
    return 0;
}



