#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int v[5], min = 255, max = 0, sum = 0;
        char met[11];
        scanf("%s", met);

        for(int j = 0; j < 3; j++) {
            scanf("%d", &v[j]);

            if(v[j] < min) {
                min = v[j];
            }

            if(v[j] > max) {
                max = v[j];
            }

            sum += v[j];
        }

        double eye = floor(v[0] * 0.3 + v[1] * 0.59 + v[2] * 0.11);
        
        if(strcmp(met, "min") == 0) {
            printf("Caso #%d: %d\n", i + 1, min);
        } else if(strcmp(met, "max") == 0) {
            printf("Caso #%d: %d\n", i + 1, max);
        } else if(strcmp(met, "mean") == 0) {
            printf("Caso #%d: %d\n", i + 1, sum / 3);
        } else if(strcmp(met, "eye") == 0) {
            printf("Caso #%d: %.0lf\n", i + 1, eye);
        }
                
    }
    
    return 0;
}

