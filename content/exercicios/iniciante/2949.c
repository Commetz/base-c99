#include <stdio.h>

int main() {

    int n, conta = 0, conte = 0, conth = 0, contm = 0, contx = 0;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        char nome[50], r[2];
        scanf("%s %c", nome, r);

        if(r[0] == 'A') {
            conta++;
        } else if(r[0] == 'E') {
            conte++;
        } else if(r[0] == 'H') {
            conth++;
        } else if(r[0] == 'M') {
            contm++;
        } else if(r[0] == 'X') {
            contx++;
        }
    }

    printf("%d Hobbit(s)\n", contx);
    printf("%d Humano(s)\n", conth);
    printf("%d Elfo(s)\n", conte);
    printf("%d Anao(oes)\n", conta);
    printf("%d Mago(s)\n", contm);
    
    return 0;
}
