#include <stdio.h>

int main() {
  
  int b;
  scanf("%d", &b);

  int g;
  scanf("%d", &g);

  if (g % 2 != 0) {
    g -= 1;
  }

  int x = g /2;  

  int c = x - b;

  if (c <= 0) {
    printf("Amelia tem todas bolinhas!\n");
  } else {
    printf("Faltam %d bolinha(s)\n", x - b);
  }

  return 0;
}

