#include <stdio.h>
#include <string.h>

int main() {

    char bin[111];
    scanf("%s", bin);

    int cont = 0, t = strlen(bin);
    for(int i = 0; i < t; i++) {
        cont += bin[i];
    }

    if(cont % 2 == 0) {
        printf("%s0\n", bin);
    } else {
        printf("%s1\n", bin);
    }
    
    return 0;
}

