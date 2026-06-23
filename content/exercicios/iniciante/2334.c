#include <stdio.h>
#include <string.h>

int main() {
    
    while(1) {
        char p[30];
        scanf("%s", p);
        
        if(strcmp(p, "0") == 0) {
            printf("0\n");
        } else if(strcmp(p, "-1") == 0) {
            return 0;
        } else {
            int tamanho = strlen(p);
            int i = tamanho - 1;
        
            for(; i >= 0; i++) {
                if(p[i] > '0') {
                    p[i]--;
                    break;
                } else {
                    p[i] = '9';
                    i--;
                }
            }
            
            int cont = 0;
            
            while(p[cont] == '0' && p[cont+1] != '\0') {
                cont++;
            }
        
            printf("%s\n", p + cont);
        }
    }
}   
    
    
