// 1016 Beecrowd - Distância
// Por Commetz
#include <stdio.h>

int main() {

    // Declarando variáveis de valores inteiros para os dois carros, a distância e o tempo
    int carro_x, carro_y, distancia, tempo;
    // Lendo o valor da distância do valor que y quer estar à frente de x
    scanf("%d", &distancia);
    
    // Afirmando os valores dos carros, sendo o carro x com 60km/h e o carro y com 90km/h
    carro_x = 60;
    carro_y = 90;
    // Calculando o tempo em que y fica "distancia" à frente de x, sendo o tempo em minutos
    tempo = (distancia * 2);
    
    // Imprimindo o tempo em que y ultrapassa x conforme requisitado, sendo o tempo em minutos
    printf("%d minutos\n", tempo);

    return 0;
}