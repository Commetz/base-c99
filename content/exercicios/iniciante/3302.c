#include <stdio.h>

int main() {

  int x;
  scanf("%d", &x);

  for(int i = 1; i <= x; i++) {
    int y;
    scanf("%d", &y);

    printf("resposta %d: %d\n", i, y);

  }

  return 0;
}
