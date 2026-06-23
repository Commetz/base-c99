#include <stdio.h>
#include <string.h>

int main() {

  char p[21];

  scanf("%s", p);

  int t = strlen(p);

  if(t >= 10) {
    printf("palavrao\n");
  } else {
    printf("palavrinha\n");
  }

  return 0;
}
