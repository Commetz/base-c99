#include <stdio.h>
#include <string.h>

int main() {

    char s[301];

    int n; 
    
    while(scanf("%d\n", &n) != EOF) {
        for(int i = 0; i < n; i++) {
            int cont = 0, conte = 0, conts = 0;
            
            fgets(s, sizeof(s), stdin);
            s[strcspn(s, "\n")] = 0;
            
            int t = strlen(s);
            
            for(int j = 0; j < t; j++) {
                if(s[j] == '.') {
                    conts++;
                } else {
                    conts = 0;
                    conte++;
                }
            }
    
            int carry = conte * 3;
            cont += carry + (conts - 1);
            
            char r = cont + 'a';
            
            printf("%c\n", r);
        }
    }
    
    return 0;
}

