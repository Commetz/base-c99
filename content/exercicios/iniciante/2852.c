#include <stdio.h>
#include <string.h>
#include <ctype.h>

int vogal(char c) {
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

int main() {
    char key[50];
    scanf("%s", key);

    int K = strlen(key);

    int N;
    scanf("%d", &N);
    getchar();

    char msg[100005];

    while (N--) {
        fgets(msg, sizeof(msg), stdin);

        int len = strlen(msg);
        if (len && msg[len - 1] == '\n')
            msg[--len] = '\0';

        int kpos = 0;
        int inicio_palavra = 1;
        int criptografa = 0;

        for (int i = 0; msg[i]; i++) {
            char c = msg[i];

            if (c == ' ') {
                inicio_palavra = 1;
                criptografa = 0;
                continue;
            }

            if (inicio_palavra) {
                criptografa = !vogal(c);
                inicio_palavra = 0;
            }

            if (criptografa) {
                int p = c - 'a';
                int k = key[kpos] - 'a';

                msg[i] = 'a' + (p + k) % 26;
                kpos = (kpos + 1) % K;
            }
        }

        printf("%s\n", msg);
    }

    return 0;
}
