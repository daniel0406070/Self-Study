#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <malloc.h>

#define size 1000

typedef struct complex *cptr;
typedef struct complex{
    double real;
    double imag;
}complex;

int main(){
    int n=10;
    
    int *a = (int*)malloc(sizeof(int) * n);

    cptr ans = (cptr)malloc(sizeof(complex) * size);


    cptr c[10];
    for(int i=0; i<10; i++)
        c[0] = (cptr)malloc(sizeof(complex) * size);

    return 0;
}

