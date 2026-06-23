#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int jogo(char esc1[20], char esc2[20]) {
    if(strcmp(esc1, "tesoura") == 0) {
        if(strcmp(esc2, "papel") == 0 || strcmp(esc2, "lagarto") == 0) {
            return 1;
        } else if (strcmp(esc2, "Spock") == 0 || strcmp(esc2, "pedra") == 0) {
            return 2;
        } else {
            return 3;
        }
    } else if (strcmp(esc1, "papel") == 0) {
        if(strcmp(esc2, "pedra") == 0 || strcmp(esc2, "Spock") == 0) {
            return 1;
        } else if (strcmp(esc2, "lagarto") == 0 || strcmp(esc2, "tesoura") == 0) {
            return 2;
        } else {
            return 3;
        }
    } else if (strcmp(esc1, "pedra") == 0) {
        if(strcmp(esc2, "lagarto") == 0 || strcmp(esc2, "tesoura") == 0) {
            return 1;
        } else if (strcmp(esc2, "Spock") == 0 || strcmp(esc2, "papel") == 0) {
            return 2;
        } else {
            return 3;
        }
    } else if (strcmp(esc1, "lagarto") == 0) {
        if (strcmp(esc2, "Spock") == 0 || strcmp(esc2, "papel") == 0) {
            return 1;
        } else if (strcmp(esc2, "pedra") == 0 || strcmp(esc2, "tesoura") == 0) {
            return 2;
        } else {
            return 3;
        }
    } else if (strcmp(esc1, "Spock") == 0) {
        if (strcmp(esc2, "tesoura") == 0 || strcmp(esc2, "pedra") == 0) {
            return 1;
        } else if (strcmp(esc2, "lagarto") == 0 || strcmp(esc2, "papel") == 0) {
            return 2;
        } else {
            return 3;
        }
    }
}

int main() {
    
    int n;
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i++) {
        char esc1[20], esc2[20];
        scanf("%s %s", esc1, esc2);
        
        if(jogo(esc1, esc2) == 1) {
            printf("Caso #%d: Bazinga!\n", i);
        } else if (jogo(esc1, esc2) == 2) {
            printf("Caso #%d: Raj trapaceou!\n", i);
        } else {
            printf("Caso #%d: De novo!\n", i);
        }
    }
    
    return 0;
}
