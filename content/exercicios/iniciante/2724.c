#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOK 60
#define MAXLEN 55

typedef struct {
    int n;
    char tok[MAXTOK][MAXLEN];
} Formula;

void parse_formula(char *s, Formula *f) {
    int i = 0, len = strlen(s);
    f->n = 0;

    while (i < len) {
        int p = 0;

        f->tok[f->n][p++] = s[i++]; /* letra maiúscula */

        while (i < len && islower((unsigned char)s[i]))
            f->tok[f->n][p++] = s[i++];

        while (i < len && isdigit((unsigned char)s[i]))
            f->tok[f->n][p++] = s[i++];

        f->tok[f->n][p] = '\0';
        f->n++;
    }
}

int contains(Formula *exp, Formula *danger) {
    if (danger->n > exp->n) return 0;

    for (int i = 0; i + danger->n <= exp->n; i++) {
        int ok = 1;

        for (int j = 0; j < danger->n; j++) {
            if (strcmp(exp->tok[i + j], danger->tok[j]) != 0) {
                ok = 0;
                break;
            }
        }

        if (ok) return 1;
    }

    return 0;
}

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        int T;
        scanf("%d", &T);

        Formula danger[55];

        for (int i = 0; i < T; i++) {
            char s[MAXLEN];
            scanf("%s", s);
            parse_formula(s, &danger[i]);
        }

        int U;
        scanf("%d", &U);

        for (int i = 0; i < U; i++) {
            char s[MAXLEN];
            Formula exp;

            scanf("%s", s);
            parse_formula(s, &exp);

            int bad = 0;

            for (int j = 0; j < T && !bad; j++) {
                if (contains(&exp, &danger[j]))
                    bad = 1;
            }

            puts(bad ? "Abortar" : "Prossiga");
        }

        if (N) putchar('\n');
    }

    return 0;
}
