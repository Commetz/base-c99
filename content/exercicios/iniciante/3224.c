#include <stdio.h>
#include <string.h>

int main() {

  char a[1001], b[1001];
  scanf("%s %s", a, b);

  int x = strlen(a), y = strlen(b);

  if(x > y) {
    printf("no\n");
  } else {
    printf("go\n");
  }

  return 0;
}
