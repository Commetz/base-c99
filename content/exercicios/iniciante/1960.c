#include <stdio.h>

int main() {

    int a; 
    scanf("%d", &a);

    int m = a / 1000;
    int cm = (a % 1000) / 900;
    int d = ((a % 1000) % 900) / 500;
    int cd = (((a % 1000) % 900) % 500) / 400;
    int c = ((((a % 1000) % 900) % 500) % 400) / 100;
    int xc = (((((a % 1000) % 900) % 500) % 400) % 100) / 90;
    int l = ((((((a % 1000) % 900) % 500) % 400) % 100) % 90) / 50;
    int xl = (((((((a % 1000) % 900) % 500) % 400) % 100) % 90) % 50) / 40;
    int x = ((((((((a % 1000) % 900) % 500) % 400) % 100) % 90) % 50) % 40) / 10;
    int ix = (((((((((a % 1000) % 900) % 500) % 400) % 100) % 90) % 50) % 40) % 10) / 9;
    int v = ((((((((((a % 1000) % 900) % 500) % 400) % 100) % 90) % 50) % 40) % 10) % 9) / 5;
    int iv = (((((((((((a % 1000) % 900) % 500) % 400) % 100) % 90) % 50) % 40) % 10) % 9) % 5) / 4;
    int i = (((((((((((a % 1000) % 900) % 500) % 400) % 100) % 90) % 50) % 40) % 10) % 9) % 5) % 4;

    for(int j = 0; j < m; j++) {
        printf("M");
    }

    for(int j = 0; j < cm; j++) {
        printf("CM");
    }

    for(int j = 0; j < d; j++) {
        printf("D");
    }

    for(int j = 0; j < cd; j++) {
        printf("CD");
    }

    for(int j = 0; j < c; j++) {
        printf("C");
    }

    for(int j = 0; j < xc; j++) {
        printf("XC");
    }

    for(int j = 0; j < l; j++) {
        printf("L");
    }

    for(int j = 0; j < xl; j++) {
        printf("XL");
    }

    for(int j = 0; j < x; j++) {
        printf("X");
    }

    for(int j = 0; j < ix; j++) {
        printf("IX");
    }

    for(int j = 0; j < v; j++) {
        printf("V");
    }

    for(int j = 0; j < iv; j++) {
        printf("IV");
    }

    for(int j = 0; j < i; j++) {
        printf("I");
    }

    printf("\n");

    return 0;
}
