#include <stdio.h>
#include <string.h>

int ultima_posicao(const char *str, const char *sub) {
    int len_str = strlen(str);
    int len_sub = strlen(sub);
    int ultima = -1;  

    if (len_sub == 0 || len_sub > len_str) return -1;

    for (int i = 0; i <= len_str - len_sub; i++) {
        if (strncmp(&str[i], sub, len_sub) == 0) {
            ultima = i;          
        }
    }

    return ultima; 
}

int contar_ocorrencias(const char *string, const char *substring) {
    int count = 0;
    size_t len_sub = strlen(substring);
    size_t len_str = strlen(string);

    if (len_sub == 0 || len_sub > len_str) {
        return 0;
    }

    for (size_t i = 0; i <= len_str - len_sub; i++) {
        if (strncmp(&string[i], substring, len_sub) == 0) {
            count++;
            i += len_sub - 1; 
        }
    }
    return count;
}

int main() {

    char numero[20];

    int i = 1;
    
    while(scanf("%s", numero) != EOF) {
        char frase[50];
        scanf("%s", frase);
        
        int qnt = contar_ocorrencias(frase, numero);
        int pos = ultima_posicao(frase, numero) + 1;
        
        printf("Caso #%d:\n", i);

        if(qnt == 0) {
            printf("Nao existe subsequencia\n\n");
        } else {
            printf("Qtd.Subsequencias: %d\n", qnt);
            printf("Pos: %d\n\n", pos);
        }
        i++;
    }

    return 0;
}   

