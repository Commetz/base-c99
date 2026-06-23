#include <stdio.h>
#include <string.h>

void transform(char origem[], char destino[], int t) {
    for(int i = 0; i < t; i++) {
        if(origem[i] >= 'a' && origem[i] <= 'z')
            destino[i] = origem[i] - 32;
        else if(origem[i] >= 'A' && origem[i] <= 'Z')
            destino[i] = origem[i] + 32;
        else
            destino[i] = origem[i];
    }
}

int main() {

    int a, b; 
    
    while(scanf("%d %d", &a, &b) != EOF) {
        char p0[250], p1[250];
        getchar();
        scanf("%[^\n]", p0);
        getchar();
        scanf("%[^\n]", p1);
        
        char p2[250];
        char p3[250];

        transform(p0, p2, a);
        transform(p1, p3, a);

        for(int i = 0; i < b; i++) {
            char frase[100001];
            getchar();
            scanf("%100000[^\n]", frase);

            int t = strlen(frase);

            for(int j = 0; j < t; j++) {
                int cont = 0;
                for(int k = 0; k < a; k++) {
                    if(frase[j] > 'z' || frase[j] < 'a' || frase[j] > 'Z' || frase[j] < 'A') {
                        if(frase[j] == p2[k]) {
                            printf("%c", p3[k]);
                            cont = 1;
                            break;
                        } else if(frase[j] == p3[k]) {
                            printf("%c", p2[k]);
                            cont = 1;
                            break;
                        } else if(frase[j] == p0[k]) {
                            printf("%c", p1[k]);
                            cont = 1;
                            break;
                        } else if(frase[j] == p1[k]) {
                            printf("%c", p0[k]);
                            cont = 1;
                            break;
                        }
                    } else {
                        if(frase[j] == p0[k]) {
                            printf("%c", p1[k]);
                            cont = 1;
                            break;
                        } else if(frase[j] == p1[k]) {
                            printf("%c", p0[k]);
                            cont = 1;
                            break;
                        } else if(frase[j] == p2[k]) {
                            printf("%c", p3[k]);
                            cont = 1;
                            break;
                        } else if(frase[j] == p3[k]) {
                            printf("%c", p2[k]);
                            cont = 1;
                            break;
                        } 
                    }
                }

                if(cont == 0) {
                    printf("%c", frase[j]);
                }

            }

            printf("\n");
            
        }
        
        printf("\n");
        
    } 
    
    return 0;
}

