#include <stdio.h>

int main() {
    
    int n;
    char k[2];
    
    scanf("%d", &n);
    scanf("%s", &k);
    
    int moeda;
    if(k[0] == 'A') {
        moeda = 1;
    } else if (k[0] == 'B') {
        moeda = 2;
    } else {
        moeda = 3;
    }
    
    for(int i = 0; i < n; i++) {
        int movimento = 0;
        scanf("%d", &movimento);
        
        if(movimento == 1 && moeda == 1) {
            moeda = 2;
        } else if (movimento == 1 && moeda == 2) {
            moeda = 1;
        } else if (movimento == 2 && moeda == 2) {
            moeda = 3;
        } else if (movimento == 2 && moeda == 3) {
            moeda = 2;
        } else if (movimento == 3 && moeda == 1) {
            moeda = 3;
        } else if (movimento == 3 && moeda == 3) {
            moeda = 1;
        }
    }
    
    if (moeda == 1) {
        printf("A\n");
    } else if (moeda == 2) {
        printf("B\n");
    } else {
        printf("C\n");
    }
    
    return 0;
}
