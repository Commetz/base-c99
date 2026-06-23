#include <stdio.h>
#include <string.h>

int main() {
    
    char e0[11], e1[11], e2[11];
    
    while(scanf("%s %s %s", e0, e1, e2) != EOF) {
        int t0 = 0, t1 = 0, t2 = 0;
    
        if(strcmp(e0, "pedra") == 0) {
            t0 = 1;
        } else if(strcmp(e0, "papel") == 0) {
            t0 = 2;
        } else {
            t0 = 3;
        }
    
        if(strcmp(e1, "pedra") == 0) {
            t1 = 1;
        } else if(strcmp(e1, "papel") == 0) {
            t1 = 2;
        } else {
            t1 = 3;
        }
    
        if(strcmp(e2, "pedra") == 0) {
            t2 = 1;
        } else if(strcmp(e2, "papel") == 0) {
            t2 = 2;
        } else {
            t2 = 3;
        }
    
        if(t0 == 1 && t1 == 3 && t2 == 3) {
            printf("Os atributos dos monstros vao ser inteligencia, sabedoria...\n");
        } else if(t0 == 2 && t1 == 1 && t2 == 1) {
            printf("Os atributos dos monstros vao ser inteligencia, sabedoria...\n");
        } else if(t0 == 3 && t1 == 2 && t2 == 2) {
            printf("Os atributos dos monstros vao ser inteligencia, sabedoria...\n");
        } else if(t1 == 1 && t0 == 3 && t2 == 3) {
            printf("Iron Maiden's gonna get you, no matter how far!\n");
        } else if(t1 == 2 && t0 == 1 && t2 == 1) {
            printf("Iron Maiden's gonna get you, no matter how far!\n");
        } else if(t1 == 3 && t0 == 2 && t2 == 2) {
            printf("Iron Maiden's gonna get you, no matter how far!\n");
        } else if(t2 == 1 && t0 == 3 && t1 == 3) {
            printf("Urano perdeu algo muito precioso...\n");
        } else if(t2 == 2 && t0 == 1 && t1 == 1) {
            printf("Urano perdeu algo muito precioso...\n");
        } else if(t2 == 3 && t0 == 2 && t1 == 2) {
            printf("Urano perdeu algo muito precioso...\n");
        } else {
            printf("Putz vei, o Leo ta demorando muito pra jogar...\n");
        }
    }
    
    return 0;
}
