#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    getchar();

    char line[50];

    for (int i = 0; i < N; i++) {
        fgets(line, sizeof(line), stdin);

        if (strstr(line, "P=NP") != NULL) {
            printf("skipped\n");
        } else {
            int a, b;
            sscanf(line, "%d+%d", &a, &b);
            printf("%d\n", a + b);
        }
    }

    return 0;
}
