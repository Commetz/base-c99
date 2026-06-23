#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 200003

typedef struct Node {
    char *str;
    struct Node *next;
} Node;

Node *hashTable[HASH_SIZE];

unsigned long hash(const char *s) {
    unsigned long h = 5381;
    while (*s) {
        h = ((h << 5) + h) + (*s++);
    }
    return h % HASH_SIZE;
}

int main() {
    char jewel[1000001];
    int distinct = 0;

    while (scanf("%s", jewel) != EOF) {
        unsigned long h = hash(jewel);

        Node *cur = hashTable[h];
        int found = 0;

        while (cur) {
            if (strcmp(cur->str, jewel) == 0) {
                found = 1;
                break;
            }
            cur = cur->next;
        }

        if (!found) {
            Node *newNode = (Node *)malloc(sizeof(Node));
            newNode->str = (char *)malloc(strlen(jewel) + 1);
            strcpy(newNode->str, jewel);

            newNode->next = hashTable[h];
            hashTable[h] = newNode;

            distinct++;
        }
    }

    printf("%d\n", distinct);

    return 0;
}
