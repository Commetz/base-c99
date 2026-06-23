#include <stdio.h>
#include <math.h>

int main() {

  int x;
  scanf("%d", &x);

  int quadrado = pow(x, 2);

  if(x % 2 == 0) {
    printf("%d casas brancas e %d casas pretas\n", quadrado / 2, quadrado / 2);
  } else {
    printf("%d casas brancas e %d casas pretas\n", (quadrado / 2) + 1, (quadrado / 2));
  }

  return 0;
}
