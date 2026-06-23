#include <stdio.h>
#include <stdlib.h>

// Função para calcular o Máximo Divisor Comum (sempre positivo)
long long gcd(long long a, long long b) {
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : b;
    while (b) {
        long long temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

// Estruturas para registrar linhas e direções únicas
struct Line { long long A, B, C; };
struct Dir { long long A, B; };

int main() {
    int w, n;
    
    // Processa até o final do arquivo (EOF), o que é padrão para o Beecrowd
    while (scanf("%d %d", &w, &n) == 2) {
        struct Line lines[105];
        int num_lines = 0;

        struct Dir dirs[105];
        int num_dirs = 0;

        for (int i = 0; i < n; i++) {
            long long x1, y1, x2, y2;
            scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);

            // Equação da reta Ax + By + C = 0
            long long A = y1 - y2;
            long long B = x2 - x1;
            long long C = x1 * y2 - x2 * y1;

            long long g_dir = gcd(A, B);
            long long g_line = gcd(g_dir, C);

            // Normalizando a Linha Inteira (A, B, C)
            long long lA = A / g_line;
            long long lB = B / g_line;
            long long lC = C / g_line;

            // Ajuste de sinais padronizado para identificar se são idênticas
            if (lA < 0 || (lA == 0 && lB < 0) || (lA == 0 && lB == 0 && lC < 0)) {
                lA = -lA;
                lB = -lB;
                lC = -lC;
            }

            int found_line = 0;
            for (int j = 0; j < num_lines; j++) {
                if (lines[j].A == lA && lines[j].B == lB && lines[j].C == lC) {
                    found_line = 1;
                    break;
                }
            }
            if (!found_line) {
                lines[num_lines].A = lA;
                lines[num_lines].B = lB;
                lines[num_lines].C = lC;
                num_lines++;
            }

            // Normalizando apenas a Direção / Inclinação (A, B)
            long long dA = A / g_dir;
            long long dB = B / g_dir;

            if (dA < 0 || (dA == 0 && dB < 0)) {
                dA = -dA;
                dB = -dB;
            }

            int found_dir = 0;
            for (int j = 0; j < num_dirs; j++) {
                if (dirs[j].A == dA && dirs[j].B == dB) {
                    found_dir = 1;
                    break;
                }
            }
            if (!found_dir) {
                dirs[num_dirs].A = dA;
                dirs[num_dirs].B = dB;
                num_dirs++;
            }
        }

        // Determina a quantidade de regiões infinitas atual
        int current_regions;
        if (num_dirs <= 1) {
            current_regions = num_lines + 1; // Todas as retas são paralelas
        } else {
            current_regions = 2 * num_lines; // Retas se cruzam
        }

        // Verifica o que precisamos adicionar
        if (current_regions >= w) {
            printf("0\n");
        } else {
            // A fórmula (w + 1) / 2 em inteiros equivale ao "Teto" de w / 2
            int required_A = (w + 1) / 2 - num_lines;
            
            // Garantir que adicionaremos ao menos 1 linha caso as antigas
            // fossem paralelas e precisassem "saltar" para o status cruzado
            if (required_A < 1) required_A = 1;
            
            printf("%d\n", required_A);
        }
    }

    return 0;
}
