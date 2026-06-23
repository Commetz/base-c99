#include <stdio.h>
#include <string.h>

int main() {

    int a;
    
    while(scanf("%d", &a) != EOF) {
        char palavras[a+1][101];
        for(int i = 0; i < a; i++) {
            scanf("%100s", palavras[i]);
        }
            
        int b;
        scanf("%d", &b);

        for(int i = 0; i < b; i++) {
            char busca[101], selecionado[a+1][101];
            scanf("%s", busca);

            int tb = strlen(busca), contp = 0, linha = 0;

            for(int j = 0; j < a; j++) {  
                int cont = 0;
                for(int k = 0; k < tb; k++) {
                    if(busca[k] == palavras[j][k]) {
                        cont++;
                    }

                    if(cont == tb) {
                        contp++;
                        strcpy(selecionado[linha], palavras[j]);
                        linha++;
                        break;
                    }
                }
            }

            int maior = 0;

            for(int i = 0; i < linha + 1; i++) {
                int t = strlen(selecionado[i]);

                if(t > maior) {
                    maior = t;
                }
            }

            if(contp != 0) {
                printf("%d %d\n", contp, maior);
            } else {
                printf("-1\n");
            }
            
        }
    }

    return 0;
}
