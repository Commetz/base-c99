// 1019 Beecrowd - Conversão de Tempo
// Por Commetz
#include <stdio.h>

int main() {

    // Declarando as variáveis de valores inteiros "tempo", "horas", "minutos" e "segundos" para guardar o resultado da conversão do tempo 
    int tempo, horas, minutos, segundos;
    // Lendo a variável "tempo" (tempo em segundos)
    scanf("%d", &tempo);

    // Calculando a quantidade de horas, minutos e segundos a partir do tempo total em segundos, utilizando a divisão inteira e o operador módulo para obter os valores restantes
    horas = tempo / 3600;
    minutos = (tempo % 3600) / 60;
    segundos = (tempo % 3600) % 60;

    // Exibindo a quantidade de horas, minutos e segundos conforme requisitado no formato "horas:minutos:segundos"
    printf("%d:%d:%d\n", horas, minutos, segundos);
  
    return 0;
}
