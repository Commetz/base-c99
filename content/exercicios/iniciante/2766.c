#include <stdio.h>

int main() {

    for(int i = 0; i < 10; i++) {
        char palavra[50];
        scanf("%s", palavra);

        if(i == 2 || i == 6 || i == 8) {
            printf("%s\n", palavra);
        }
    }
    
    return 0;
}
