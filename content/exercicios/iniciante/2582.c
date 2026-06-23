#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int x, y; 
        scanf("%d %d", &x, &y);

        int z = x + y;

        if(z == 0){
            printf("PROXYCITY\n");
        } else if(z == 1) {
            printf("P.Y.N.G.\n");
        } else if(z == 2) {
            printf("DNSUEY!\n");
        } else if(z == 3) {
            printf("SERVERS\n");
        } else if(z == 4) {
            printf("HOST!\n");
        } else if(z == 5) {
            printf("CRIPTONIZE\n");
        } else if(z == 6) {
            printf("OFFLINE DAY\n");
        } else if(z == 7) {
            printf("SALT\n");
        } else if(z == 8) {
            printf("ANSWER!\n");
        } else if(z == 9) {
            printf("RAR?\n");
        } else if(z == 10) {
            printf("WIFI ANTENNAS\n");
        }
    }
    
    return 0;
}
