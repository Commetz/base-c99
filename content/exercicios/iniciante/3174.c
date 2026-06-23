#include <stdio.h>
#include <string.h>

int main() {

    int n;
    scanf("%d", &n);

    char nome[20], trab[20];
    int horas;
    
    int boneco = 0, arquiteto = 0, musico = 0, desenhista = 0;
    
    for(int i = 0; i < n; i++) {
        scanf("%s %s %d", nome, trab, &horas);
    
        if(trab[0] == 'b') {
            boneco += horas;
        } else if (trab[0] == 'a') {
            arquiteto += horas;
        } else if (trab[0] == 'm') {
            musico += horas;
        } else if (trab[0] == 'd') {
            desenhista += horas;
        }
    }
    
    int soma = (boneco / 8) + (arquiteto / 4) + (musico / 6) + (desenhista / 12); 
    
    printf("%d\n", soma);

    return 0;
}

