#include <stdio.h>
#include <string.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int w, h, x0, y0;
        scanf("%d %d %d %d", &w, &h, &x0, &y0);

        char elemento[11];
        int level, cx, cy;
        scanf("%s %d %d %d", elemento, &level, &cx, &cy);

        int dano, raio;

        if (strcmp(elemento, "fire") == 0) {
            dano = 200;
            if (level == 1) raio = 20;
            else if (level == 2) raio = 30;
            else raio = 50;
        }
        else if (strcmp(elemento, "water") == 0) {
            dano = 300;
            if (level == 1) raio = 10;
            else if (level == 2) raio = 25;
            else raio = 40;
        }
        else if (strcmp(elemento, "earth") == 0) {
            dano = 400;
            if (level == 1) raio = 25;
            else if (level == 2) raio = 55;
            else raio = 70;
        }
        else { 
            dano = 100;
            if (level == 1) raio = 18;
            else if (level == 2) raio = 38;
            else raio = 60;
        }

        int px = cx;
        if (px < x0) px = x0;
        if (px > x0 + w) px = x0 + w;

        int py = cy;
        if (py < y0) py = y0;
        if (py > y0 + h) py = y0 + h;

        long long dx = cx - px;
        long long dy = cy - py;

        if (dx * dx + dy * dy <= (long long)raio * raio)
            printf("%d\n", dano);
        else
            printf("0\n");
    }

    return 0;
}
