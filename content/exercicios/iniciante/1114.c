#include <stdio.h>

int main() {

    while(1) {
        int senha;
        scanf("%d", &senha);
        
        if(senha == 2002) {
            printf("Acesso Permitido\n");
            return 0;
        } else {
            printf("Senha Invalida\n");
        }
    }

    return 0;
}
