#include <stdio.h>
#include <string.h>

int main() {

    char linha[100001];
    int cont = 0;

    while (1) {
        fgets(linha, sizeof(linha), stdin);
        linha[strcspn(linha, "\n")] = '\0';

        if(strcmp(linha, "<body>") == 0 || strcmp(linha, "    <body>") == 0) {
            cont = 1;
        } else if(strcmp(linha, "</body>") == 0 || strcmp(linha, "    </body>") == 0) {
            return 0;
        } else if(cont) {
            printf("%s\n", linha);
        }
    }

    return 0;
}
