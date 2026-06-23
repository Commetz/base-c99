#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int meio(int numero) {
    if(numero > 12) {
        return numero - 13;
    } else {
        return numero + 13;
    }
}

int letra(char letra) {
    int valor = letra - 'a';
    return valor;
}

int main() {
    
    char frase1[1000000];
    char frase2[1000000];
    
    scanf("%s", frase1);
    scanf("%s", frase2);
    
    int tamanho = strlen(frase1), sum = 0;
    
    for(int i = 0; i < tamanho; i++) {
        if(frase1[i] != frase2[i]) {
            int letra1 = letra(frase1[i]);
            int letra2 = letra(frase2[i]);
            
            if(letra2 > meio(letra1)) {
                int valor = abs(abs(letra2-(meio(letra1)))-13);
                sum += valor;
            } else {
                int valor = abs(abs((meio(letra1))-letra2)-13);
                sum += valor;
            }
        }
    }
    
    printf("%d\n", sum);
    
    return 0;
}
