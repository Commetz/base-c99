#include <stdio.h>

int main() {

    int m, n;
    
    while(scanf("%d %d", &m, &n) != EOF) {
        
        int dias = 0;

        if(m >= 12 && n > 25) {
            printf("Ja passou!\n");
        } else {
            for(int i = m; i < 12; i++) {
                if(i == 2) {
                    dias += 29;
                } else if((i % 2 != 0 && i < 8) || i == 8 || i == 10) {
                    dias += 31;
                } else {
                    dias += 30;
                }
            }

            dias += (25 - n);

            if(dias == 0) {
                printf("E natal!\n");
            } else if(dias == 1) {
                printf("E vespera de natal!\n");
            } else {
                printf("Faltam %d dias para o natal!\n", --dias);
            }
        }
    }
    
    return 0;
}

