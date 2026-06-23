#include <stdio.h>
#include <string.h>

int main() {

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        char placa[101];
        scanf("%s", placa);
        
        int t = strlen(placa);

        if(placa[3] == '-' && placa[0] >= 'A' && placa[0] <= 'Z' && placa[1] >= 'A' && placa[1] <= 'Z' && placa[2] >= 'A' && placa[2] <= 'Z' && placa[4] >= '0' && placa[4] <= '9' && placa[5] >= '0' && placa[5] <= '9' && placa[6] >= '0' && placa[6] <= '9' && t == 8) {
           if(placa[7] == '1' || placa[7] == '2') {
                printf("MONDAY\n");
           } else if(placa[7] == '3' || placa[7] == '4') {
                printf("TUESDAY\n");
           } else if(placa[7] == '5' || placa[7] == '6') {
                printf("WEDNESDAY\n");
           } else if(placa[7] == '7' || placa[7] == '8') {
                printf("THURSDAY\n");
           } else if(placa[7] == '0' || placa[7] == '9') {
                printf("FRIDAY\n");
           } else {
               printf("FAILURE\n");
           }
        } else {
           printf("FAILURE\n");
        }
    }
    
    return 0;
}


