#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

int main() {
    int N, L;
    
    // Leitura da entrada. Se EOF, a execução encerra em segurança.
    if (scanf("%d %d", &N, &L) != 2) return 0;

    double x;
    int X[1005];
    
    // Convertendo as posições para inteiros (centímetros) para evitar problemas com floats
    for (int i = 0; i < N; i++) {
        scanf("%lf", &x);
        X[i] = (int)round(x * 100.0);
    }

    // Buscando todas as distâncias únicas. Existem no máximo 100.000 distâncias distintas.
    bool has_diff[100005] = {false};
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int diff = abs(X[i] - X[j]);
            if (diff > 0 && diff <= 100000) {
                has_diff[diff] = true;
            }
        }
    }

    // Passando para o array de extração ordenado crescentemente
    double unique_diffs[100005];
    int num_unique = 0;
    for (int i = 1; i <= 100000; i++) {
        if (has_diff[i]) {
            unique_diffs[num_unique++] = i / 100.0;
        }
    }

    double u = 0.1; // u representa (1 / v). Queremos o menor u válido.
    bool changed = true;
    int max_passes = 1000000; 
    int passes = 0;

    // Lógica de pulos relaxados (Relaxation / Jump Logic)
    while (changed && u <= 10.0 + 1e-9 && passes < max_passes) {
        changed = false;
        passes++;
        
        for (int i = 0; i < num_unique; i++) {
            double d = unique_diffs[i];
            double p = u * d;
            
            // Encontra o múltiplo de L mais próximo
            double k = floor(p / (double)L + 0.5);
            
            // Verifica se a distância cai numa zona proibida
            if (fabs(p - k * (double)L) < 1.0 - 1e-9) {
                
                // Salta com u exatamente para o final da zona proibida detectada 
                double next_u = (k * (double)L + 1.0) / d;
                
                if (next_u > u + 1e-12) {
                    u = next_u;
                    changed = true;
                }
            }
        }
    }

    if (u > 10.0 + 1e-9) {
        printf("no fika\n");
    } else {
        printf("%.12g\n", 1.0 / u);
    }

    return 0;
}
