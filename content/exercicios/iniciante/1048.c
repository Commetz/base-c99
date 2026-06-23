#include <stdio.h>

int main() {
    
    double a;
    scanf("%lf", &a);
    
    if (a <= 400.00) {
        printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: 15 %%\n", (0.15 * a) + a, 0.15 * a);
    }
    else if (a > 400.00 && a <= 800.00) {
        printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: 12 %%\n", (0.12 * a) + a, 0.12 * a);
    }
    else if (a > 800.00 && a <= 1200.00) {
        printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: 10 %%\n", (0.10 * a) + a, 0.10 * a);
    }
    else if (a > 1200.00 && a <= 2000.00) {
        printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: 7 %%\n", (0.07 * a) + a, 0.07 * a);
    }
    else if (a > 2000.00) {
        printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: 4 %%\n", (0.04 * a) + a, 0.04 * a);
    }
    
    return 0;
}
