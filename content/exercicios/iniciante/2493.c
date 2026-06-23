#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) {
    return strcmp((const char *)a, (const char *)b);
}

int main() {

    int t;
    while(scanf("%d", &t) != EOF) {
        int x[t], y[t], z[t];

        for(int i = 0; i < t; i++) {
            scanf("%d %d=%d", &x[i], &y[i], &z[i]); 
        }
        
        char nome[t+1][51], op[t], errado[t+1][51];
        int e[t];
        
        for(int i = 0; i < t; i++) {
            scanf("%51s %d %c", nome[i], &e[i], &op[i]);
        }
       
        int j = 0, cont = 0;

        for(int i = 0; i < t; i++) {
            if(op[i] == '+' && x[e[i]-1] + y[e[i]-1] != z[e[i]-1]) {
                strcpy(errado[j++], nome[i]);
                cont++;
            } else if(op[i] == '-' && x[e[i]-1] - y[e[i]-1] != z[e[i]-1]) {
                strcpy(errado[j++], nome[i]);
                cont++;
            } else if(op[i] == '*' && x[e[i]-1] * y[e[i]-1] != z[e[i]-1]) {
                strcpy(errado[j++], nome[i]);
                cont++;
            } else if(op[i] == 'I' && (x[e[i]-1] + y[e[i]-1] == z[e[i]-1] || x[e[i]-1] - y[e[i]-1] == z[e[i]-1] || x[e[i]-1] * y[e[i]-1] == z[e[i]-1])) {
                strcpy(errado[j++], nome[i]);
                cont++;
            } 
        }
            
        if(cont == t) {
            printf("None Shall Pass!\n");
        } else if(cont == 0) {
            printf("You Shall All Pass!\n");
        } else {
            qsort(errado, j, sizeof(errado[0]), cmp);
            for(int i = 0; i < j; i++) {
                printf("%s", errado[i]);
                if(i < j - 1) printf(" ");
            }
            printf("\n");
        }
    }
    
    return 0;
}

