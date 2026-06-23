#include <stdio.h>
#include <string.h>

int main() {
    char a[20], b[20], c[20];
    scanf("%s", a);
    
    if (strcmp(a, "vertebrado") == 0) {
        scanf("%s", b);
        if (strcmp(b, "ave") == 0) {
            scanf("%s", c);
            if (strcmp(c, "carnivoro") == 0) {
                printf("aguia\n");
            } else {
                printf("pomba\n");
            }
        } else {
            scanf("%s", c);
            if (strcmp(c, "onivoro") == 0) {
                printf("homem\n");
            } else {
                printf("vaca\n");
            }
        }
    } else {
        scanf("%s", b);
        if (strcmp(b, "inseto") == 0) {
            scanf("%s", c);
            if (strcmp(c, "hematofago") == 0) {
                printf("pulga\n");
            } else {
                printf("lagarta\n");
            }
        } else {
            scanf("%s", c);
            if (strcmp(c, "hematofago") == 0) {
                printf("sanguessuga\n");
            } else  {
                printf("minhoca\n");
            }
        }
    }

    return 0;
}

