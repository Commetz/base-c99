#include <stdio.h>

int main () {

    int opcao = 1, x, y, x1 = 0, y1 = 0, grenal = 0, z = 0;

    while(opcao == 1) {
        scanf("%d %d", &x, &y);
        printf("Novo grenal (1-sim 2-nao)\n");
        scanf("%d", &opcao);
        if(x > y) {
            x1++;
        } 
        else if (y > x) {
            y1++;
        } else {
            z+0;
        }
        grenal++;
    }

    printf("%d grenais\n", grenal);
    printf("Inter:%d\n", x1);
    printf("Gremio:%d\n", y1);
    printf("Empates:%d\n", z);
    
    if(x1 > y1) {
        printf("Inter venceu mais\n");
    }
    else if(y1 > x1) {
        printf("Gremio venceu mais\n");
    }

    return 0;
}
