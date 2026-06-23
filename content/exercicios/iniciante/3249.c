#include <stdio.h>
#include <string.h>

int main() {

    int n, cont = 0;
    
    while(scanf("%d", &n) != EOF) {

        for(int i = 0; i < n; i++) {
            char frase[100001];
    
            getchar();
    
            scanf("%s", frase);
    
            int t = strlen(frase), temd = 0, s = 0; 
    
            for(int j = t; j >= 0; j--) {
               if(frase[j] == 'D') {
                    temd = j;
               }
    
                if(frase[j] == 'C' && temd-1 == j) {
                    s = 1;
                }
            }
    
            if(s == 1) {
                cont++;
            }
        }
    
        printf("%d\n", n - cont);
    
    }
    
    return 0;
}

