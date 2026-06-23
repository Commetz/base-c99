#include <stdio.h>

int main(){
    
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    int k, sum = 0;
    scanf("%d", &k);

    for(int j = 0; j < k; j++) {
      int o;
      scanf("%d", &o);

      sum += o;
    }
    printf("%d\n", sum - (k - 1));
  } 
  
  
  return 0;
}
