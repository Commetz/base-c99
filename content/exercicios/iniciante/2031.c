#include <stdio.h>
#include <string.h>

int main() {   

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        char a[11], b[11];
        scanf("%s %s", a, b);

        int pedra1 = strcmp(a , "pedra");
        int papel1 = strcmp(a, "papel");
        int ataque1 = strcmp(a, "ataque");

        int pedra2 = strcmp(b , "pedra");
        int papel2 = strcmp(b, "papel");
        int ataque2 = strcmp(b, "ataque");

        if(ataque1 == 0 && ataque2 != 0) {
            printf("Jogador 1 venceu\n");
        }

        else if(ataque1 == 0 && ataque2 == 0) {
            printf("Aniquilacao mutua\n");
        }

        else if(ataque1 != 0 && ataque2 == 0) {
            printf("Jogador 2 venceu\n");
        }

        else if(pedra1 == 0 && pedra2 == 0) {
            printf("Sem ganhador\n");
        }

        else if(pedra1 == 0 && papel2 == 0) {
            printf("Jogador 1 venceu\n");
        }
        
        else if(papel1 == 0 && papel2 == 0) {
            printf("Ambos venceram\n");
        }

        else if(papel1 == 0 && pedra2 == 0) {
            printf("Jogador 2 venceu\n");
        }
    }
    
    return 0;
}
