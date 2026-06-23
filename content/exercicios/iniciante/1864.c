#include <stdio.h>

int main() {

	char f[30] = "LIFEISNOTAPROBLEMTOBESOLVED";

	int n, cont = 0;
	scanf("%d", &n);

	for(int i = 0; cont < n; i++) {
		if(i == 4 || i == 6 || i == 9 || i == 10 || i == 17 || i == 19 || i == 21) {
		    cont++;
			printf(" ");
		} 
		
		if(cont < n) {
		    cont++;

		    printf("%c", f[i]);
		}
	}

    printf("\n");

	return 0;
}
