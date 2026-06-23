#include <stdio.h>

int main() {

    char f1[101], f2[101];
    scanf("%[^,]", f1);
    scanf(",%[^\n]", f2);
    
    printf("%s\n%s\n", f1, f2);
    
    return 0;
}

