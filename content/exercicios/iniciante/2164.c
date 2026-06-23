#include <stdio.h>
#include <math.h>

int main() {

    int x; 
    scanf("%d", &x);

    double y = ((pow(((1 + sqrt(5)) / 2), x) - (pow(((1 - sqrt(5)) / 2), x))) / (sqrt(5)));

    printf("%.1lf\n", y);
    
    return 0;
}

