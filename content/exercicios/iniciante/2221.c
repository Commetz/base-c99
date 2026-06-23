#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int x, atk, atk1;
        scanf("%d", &x);

        int a, b, c; 
        scanf("%d %d %d", &a, &b, &c);

        int a1, b1, c1; 
        scanf("%d %d %d", &a1, &b1, &c1);

        if(c % 2 == 0) {
            atk = ((a + b) / 2) + x;
        } else {
            atk = ((a + b) / 2);
        }

        if(c1 % 2 == 0) {
            atk1 = ((a1 + b1) / 2) + x;
        } else {
            atk1 = ((a1 + b1) / 2);
        }

        
        if(atk > atk1) {
            printf("Dabriel\n");
        } else if(atk1 > atk) {
            printf("Guarte\n");
        } else {
            printf("Empate\n");
        }

    }
        
    return 0;   
}
