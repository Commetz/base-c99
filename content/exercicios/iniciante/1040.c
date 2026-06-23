// 1040 Beecrowd - Média 3
// Por Commetz
#include <stdio.h>

int main() {

    // Declaração das variáveis para as quatro notas e para o exame
    double a, b, c, d, media, exame;
    // Leitura das quatro notas
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);

    // Cálculo da média ponderada: pesos 2, 3, 4 e 1 respectivamente
    media = (2 * a + 3 * b + 4 * c + 1 * d) / 10;
    // Impressão da média inicial
    printf("Media: %.1lf\n", media);

    // Verifica se o aluno está de exame (média entre 5.0 e 6.9)
    if (media >= 5.0 && media < 7.0) {
        printf("Aluno em exame.\n");

        // Leitura da nota do exame
        scanf("%lf", &exame);
        printf("Nota do exame: %.1lf\n", exame);

        // Recalcula a média final considerando a nota do exame
        double media_final = (media + exame) / 2;

        // Verifica se o aluno foi aprovado após o exame
        if (media_final >= 5.0) {
            printf("Aluno aprovado.\n");
        } else {
            printf("Aluno reprovado.\n");
        }

        // Exibe a média final após o exame
        printf("Media final: %.1lf\n", media_final);
    } 
    // Verifica se o aluno foi aprovado diretamente (média >= 7.0)
    else if (media >= 7.0) {
        printf("Aluno aprovado.\n");
    } else {
        // Caso a média seja inferior a 5.0, o aluno está reprovado
        printf("Aluno reprovado.\n");
    }

    // Finaliza o programa
    return 0;
}
