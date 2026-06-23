#include <stdio.h>
#include <string.h>

int main() {

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        char s[10001];
        scanf("%s", s);

        double tamanho = strlen(s) / 100.00;
        printf("%.2lf\n", tamanho);
    }
    
    return 0;
}
