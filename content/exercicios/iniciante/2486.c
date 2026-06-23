#include <stdio.h>
#include <string.h>

int main() {

    int x = 1; 
    
    while(x != 0) {
        scanf("%d", &x);

        int total = 0;

        for(int i = 0; i < x; i++) {
            int quant;
            char prod[150];

            scanf("%d %[^\n]", &quant, prod);

            if(strcmp(prod, "suco de laranja") == 0) {
                total += 120 * quant;
            } else if(strcmp(prod, "morango fresco") == 0) {
                total += 85 * quant;
            } else if(strcmp(prod, "mamao") == 0) {
                total += 85 * quant;
            } else if(strcmp(prod, "goiaba vermelha") == 0) {
                total += 70 * quant;
            } else if(strcmp(prod, "manga") == 0) {
                total += 56 * quant;
            } else if(strcmp(prod, "laranja") == 0) {
                total += 50 * quant;
            } else if(strcmp(prod, "brocolis") == 0) {
                total += 34 * quant;
            }
        }
        
        if(x == 0) {
            return 0;
        }
        
        if(total > 130) {
            printf("Menos %d mg\n", total - 130);
        } else if(total < 110) {
            printf("Mais %d mg\n", 110 - total);
        } else {
            printf("%d mg\n", total);
        }
    }
    
    return 0;
}

