#include <stdio.h>
#include <string.h>

int dec_to_bin(char c[11]) {
    int cont = 0;
    
    if (c[0] == '*') {
        cont += 4;
    } 
    
    if (c[1] == '*') {
        cont += 2;
    } 
    
    if (c[2] == '*') {
        cont += 1;
    }
    
    return cont;
}

int main() {
    
    int i = 0, cont = 0;
    
    while(i != 3) {
        char olho[11], olho1[11];
        scanf("%s", olho);
        
        if(strcmp(olho, "caw") == 0) {
            scanf("%s", olho);
        }
        
        if(strcmp(olho, "caw") == 0) {
            i++;
            printf("%d\n", cont);
            cont = 0;
        } else {
            cont += dec_to_bin(olho);
        }
    }
    
    return 0;
}
