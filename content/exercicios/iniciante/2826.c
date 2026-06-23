#include <stdio.h>
#include <string.h>

int main() {

    char n[21], m[21];
    scanf("%s %s", n, m);

    int t1 = strlen(n);
    int t2 = strlen(m);
    int cont = 0;
    
    if (t1 > t2) {
        cont = t2;
    } else {
        cont = t1;
    }

    for(int i = 0; i < cont; i++) {
        if(n[i] < m[i]) {
            printf("%s\n%s\n", n, m);
            return 0;
        } else if(n[i] > m[i]) {
            printf("%s\n%s\n", m, n);
            return 0;
        }
    }
    
    if(t2 > t1) {
        printf("%s\n%s\n", n, m);
        return 0;
    } else {
        printf("%s\n%s\n", m, n);
        return 0;
    }
}   

