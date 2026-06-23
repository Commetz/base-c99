#include <stdio.h>
#include <string.h>

int main() {

    // LEITURA DE N
    int n;
    scanf("%d", &n);

    // N CASOS DE TESTE
    for(int i = 0; i < n; i++) {
        char x[4];
        int y;
        scanf("%s %d", x, &y);

        // TAMANHO PARA LIMITE DO PROX FOR
        int tamanho0 = strlen(x) - 1, tamanho1 = strlen(x) - 1;

        // VETOR PARA GUARDAR CADA NUMERO EM UMA POSICAO
        int n1[205], n2[205], vetor[205];

        for(int j = 0; j < 205; j++) {
            n1[j] = 100;
            n2[j] = 100;
            vetor[j] = 100;
        }
        
        // CONVERTENDO STRING EM INT E FAZENDO ESSE ARMAZENAMENTO
        for(int j = 0; tamanho0 >= 0; j++) {
            n1[j] = x[tamanho0] - '0';
            n2[j] = n1[j];
            tamanho0--;
        }

        tamanho0 = strlen(x);
        tamanho1 = strlen(x);

        int carry = 0, p = 0, cont = 0;

        // SE ELEAVDO A 1 O N DE DIGITOS EH O MESMO DO INICIO
        if(y == 1) {
            printf("%d\n", tamanho0);
        } else {
            // N DE VEZES QUE VOU TER QUE FAZER A MULTIPLICACAO
            for(int j = 0; j < y - 1; j++) {
                for(int o = 0; o < 205; o++) {
                    vetor[o] = 100;
                }
                // DIGITOS DO PRIMEIRO VETOR
                for(int k = 0; k < tamanho1; k++) {
                    // DIGITOS DO SEGUNDO VETOR (NÃO MUDA)
                    for(int l = 0; l < tamanho0; l++) {
                        if(vetor[p] == 100) {
                            vetor[p] = n1[l] * n2[k] + carry;
                        } else {
                            vetor[p] += n1[l] * n2[k] + carry;
                        }

                        if(vetor[p] / 10 != 0) {
                            if(vetor[p+1] != 100) {
                                vetor[p+1] += vetor[p] / 10;
                            } else {
                                vetor[p+1] = vetor[p] / 10;
                            }
                        }
                        
                        vetor[p] = vetor[p] % 10;
                        p++;
                    }
                    p -= tamanho0 - 1;
                }
               
                cont = 0;
                
                for(int k = 0; k < 205; k++) {
                    if(vetor[k] != 100) {
                        n2[k] = vetor[k];
                        cont++;
                    } else {
                        break;
                    }
                }
                
                tamanho1 = cont;
                
                p = 0;
               
            }
            
            cont = 0;

            for(int j = 0; j < 205; j++) {
                if(vetor[j] != 100) {
                    cont++;
                } else {
                    break;
                }
            }

            printf("%d\n", cont);
        }

    }

    return 0;
}   

