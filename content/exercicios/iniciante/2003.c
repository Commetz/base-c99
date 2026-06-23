#include <stdio.h>

int main() {

    int h, m;
    
    while(scanf("%d:%d", &h, &m) != EOF) {
        int tempo = h * 60 + m + 60;

        if(tempo > 480) {
            printf("Atraso maximo: %d\n", tempo - 480);
        } else {
            printf("Atraso maximo: 0\n");
        }
    }

    return 0;
}
