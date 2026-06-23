#include <stdio.h>

int main() {

  int n, x;
  scanf("%d %d", &n, &x);

  char y[n + 1];
  scanf("%s", y);

  int p, m, g;
  scanf("%d %d %d", &p, &m, &g);

  int z[300001];

  for(int i = 0; i < 300000; i++) {
    z[i] = x;
  }
  
  int pontp = 0, pontm = 0, pontg = 0;

  for(int i = 0; i < n; i++) {
    int k;
    
    if(y[i] == 'P') {
      k = p;
      
      for(int j = pontp; j < 300000; j++) {
          if(z[j] >= k) {
              z[j] -= k;
              
              break;
          } else {
                pontp += 1;
          }
      }
      
    } else if (y[i] == 'M') {
      k = m;
      
      for(int j = pontm; j < 300000; j++) {
          if(z[j] >= k) {
              z[j] -= k;
              break;
              
          } else {
                pontm += 1;
          }
      }
      
    } else if (y[i] == 'G') {
      k = g;
      
      for(int j = pontg; j < 300000; j++) {
          if(z[j] >= k) {
              z[j] -= k;
              
              break;
          } else {
                pontg += 1;
          }
      }
      
    } 
  }
  
  if(pontp >= pontm && pontp >= pontg) {
      printf("%d\n", pontp + 1);
  } else if (pontm >= pontg && pontm >= pontp) {
      printf("%d\n", pontm + 1);
  } else if (pontg >= pontm && pontg >= pontp) {
    printf("%d\n", pontg + 1);
  }
  
  return 0;
}

