#include <stdio.h>

int main() {
  
  int h, z, l;
  scanf("%d %d %d", &h, &z, &l);

  if ((h < z || h < l) && (l < h || z < h)) {
    printf("huguinho\n");
  } else if ((z < h || z < l) && (h < z || l < z)) {
    printf("zezinho\n");
  } else {
    printf("luisinho\n");
  }
  
}
