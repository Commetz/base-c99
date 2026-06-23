#include <stdio.h>
#include <string.h>

int main() {

    int n, c = 0, e = 0, gc = 0, ge = 0;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        char sd[11], sn[1];
        scanf("%s  %s", sd, sn);

        int chuva1 = strcmp(sd, "chuva");
        int chuva2 = strcmp(sn, "chuva");

        if(chuva1 == 0) {
            if(gc == 0) {
                c++;
                ge++;
            } else {
                gc--;
                ge++;
            }
        } else if(chuva2 == 0) {
            if(ge == 0) {
                e++;
                gc++;
            } else {
                ge--;
                gc++;
            }
        }
    }
    
    printf("%d %d\n", c, e);
    
    return 0;
}
