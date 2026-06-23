#include <stdio.h>
 
int main() {
    
    int c = 'a';
 
    for(int i = 0; i < 26; i++) {
        printf("%d e %c\n", i + 97, c);
        c++;
    }
 
    return 0;
}
