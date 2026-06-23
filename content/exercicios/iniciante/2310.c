#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);

    int saquet = 0, bloqueiot = 0, ataquet = 0;
    int saquect = 0, bloqueioct = 0, ataquect = 0;

    for(int i = 0; i < n; i++) {
        char nome[101];
        scanf("%s", nome);

        int saque, bloqueio, ataque;
        scanf("%d %d %d", &saque, &bloqueio, &ataque);

        saquet += saque;
        bloqueiot += bloqueio;
        ataquet += ataque;

        int saquec, bloqueioc, ataquec;
        scanf("%d %d %d", &saquec, &bloqueioc, &ataquec);

        saquect += saquec;
        bloqueioct += bloqueioc;
        ataquect += ataquec;
    }
    
    printf("Pontos de Saque: %.2lf %%.\n", saquect * 100.0 / saquet);
    printf("Pontos de Bloqueio: %.2lf %%.\n", bloqueioct * 100.0 / bloqueiot);
    printf("Pontos de Ataque: %.2lf %%.\n", ataquect * 100.0 / ataquet);
    
    return 0;
}   

