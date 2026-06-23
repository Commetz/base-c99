#include <stdio.h>
#include <string.h>

int main() {
    
    char palavra1[11], palavra2[11];
    
    while(scanf("%s", palavra1) != EOF) {

        if(strcmp(palavra1, "as") == 0) {
            scanf("%s", palavra2);
            printf("caiu\n");
        } else if(strcmp(palavra1, "esquerda") == 0) {
            printf("ingles\n");
        } else if(strcmp(palavra1, "direita") == 0) {
            printf("frances\n");
        } else if(strcmp(palavra1, "nenhuma") == 0) {
            printf("portugues\n");
        }
    }
}

