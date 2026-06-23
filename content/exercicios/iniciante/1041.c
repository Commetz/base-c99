// 1041 Beecrowd - Coordenadas de um Ponto
// Por Commetz
#include <stdio.h>

int main() {

    // Declaração das variáveis para as coordenadas x e y
    double x, y;
    // Leitura dos valores de x e y
    scanf("%lf %lf", &x, &y);

    // Verifica se o ponto está na origem
    if (x == 0 && y == 0) {
        printf("Origem\n");
    }
    // Verifica se o ponto está sobre o eixo Y
    else if (x == 0) {
        printf("Eixo Y\n");
    }
    // Verifica se o ponto está sobre o eixo X
    else if (y == 0) {
        printf("Eixo X\n");
    }
    // Verifica se o ponto está no primeiro quadrante
    else if (x > 0 && y > 0) {
        printf("Q1\n");
    }
    // Verifica se o ponto está no segundo quadrante
    else if (x < 0 && y > 0) {
        printf("Q2\n");
    }
    // Verifica se o ponto está no terceiro quadrante
    else if (x < 0 && y < 0) {
        printf("Q3\n");
    }
    // Verifica se o ponto está no quarto quadrante
    else if (x > 0 && y < 0) {
        printf("Q4\n");
    }

    return 0;
}
