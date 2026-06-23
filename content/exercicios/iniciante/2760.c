#include <stdio.h>
#include <string.h>

int main() {

    char x[101], y[101], z[101];
    scanf("%[^\n] %[^\n] %[^\n]", x, y, z);

    printf("%s%s%s\n", x, y, z);
    printf("%s%s%s\n", y, z, x);
    printf("%s%s%s\n", z, x, y);
    
    int t0 = strlen(x);
    int t1 = strlen(y);
    int t2 = strlen(z);
    int cont = 0;

    for(int i = 0; i < t0; i++) {
        printf("%c", x[i]);
        cont++;

        if(cont > 9) {
            break;
        }
    }
    
    cont = 0;

    for(int i = 0; i < t1; i++) {
        printf("%c", y[i]);
        cont++;

        if(cont > 9) {
            break;
        }
    }
    
    cont = 0;
           
    for(int i = 0; i < t2; i++) {
        printf("%c", z[i]); 
        cont++;

        if(cont > 9) {
            break;
        }
    }

    printf("\n");
    
    return 0;
}   

