#include <stdio.h>
#include <string.h>

int main() {

  char n[10000], azar = 0;
  scanf("%s", n);

  int t = strlen(n);

  for(int i = 0; i < t - 1; i++) {
    if(n[i] == '1' && n[i + 1] == '3') {
      azar = 1;
    }
  }

  if(azar == 1) {
    for(int i = 0; i < t; i++) {
      printf("%c", n[i]);
    }
    printf(" es de Mala Suerte\n");
  } else {
    for(int i = 0; i < t; i++) {
      printf("%c", n[i]);
    }
    printf(" NO es de Mala Suerte\n");
  }
  
  return 0;
}

