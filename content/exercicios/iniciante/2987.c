#include <stdio.h>

int main() {

    char letra[2];
    scanf("%c", letra);

    int dec = letra[0] - 'A' + 1;

    printf("%d\n", dec);
    
    return 0;
}
