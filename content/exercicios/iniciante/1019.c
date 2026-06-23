// 1019 Beecrowd - Conversão de Tempo
// Por Commetz
#include <stdio.h>

int main() {

    // Declarando as variáveis de valores inteiros 
    int t, h, m, s;
    // Lendo a variável "t" (tempo)
    scanf("%d", &t);

    // Calculando a quantidade de horas, minutos e segundos
    h = t / 3600;
    m = (t % 3600) / 60;
    s = (t % 3600) % 60;

    // Exibindo a quantidade de horas, minutos e segundos
    printf("%d:%d:%d\n", h, m, s);
  
    return 0;
}
