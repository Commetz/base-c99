#include <stdio.h>
#include <math.h>

int main() {
    
    int x1, y1, x2, y2, v2, r1, rc1;

    while (scanf("%d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &v2, &r1, &rc1) != EOF) {

        double distx = x2 - x1;
        double disty = y2 - y1;

        double dist = sqrt(pow(distx, 2) + (pow(disty, 2)));

        if (dist + 1.5 * v2 <= r1 + rc1)
            printf("Y\n");
        else
            printf("N\n");
    }

    return 0;
}
