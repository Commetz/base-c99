#include <stdio.h>
#include <string.h>

int main() {

    char string[15];

    while(scanf("%s", string) != EOF) {

        int cont = 0;
        int t = strlen(string);

        for(int i = 0; i < t; i++) {
            cont = cont * 26 + (string[i] - 'A' + 1);
        }

        if(cont > 16384 || cont < 1) {
            printf("Essa coluna nao existe Tobias!\n");
        } else {
            printf("%d\n", cont);
        }
    }

    return 0;
}
