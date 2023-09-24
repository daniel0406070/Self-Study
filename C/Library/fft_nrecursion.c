#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <malloc.h>

const double PI = acos(-1);

typedef struct complex *cptr;
typedef struct complex{
    double real;
    double imag;
}complex;

complex complex_add(complex a, complex b);
complex complex_sub(complex a, complex b);
complex complex_mul(complex a, complex b);
complex complex_div(complex a, complex b);

void swap(complex *a, complex *b){
    complex tmp = *a;
    *a = *b;
    *b = tmp;
}


void FFT(cptr v,int inv, int len){
    for(int i=1, j=0; i<len; i++){
        int bit = len>>1;
        while (!((j ^= bit) & bit)) bit >>= 1;
        if (i < j) {
            swap(&v[i], &v[j]);
        }
    }
    for (int i=1; i<len; i<<=1){
        double x = inv ? PI/i : -PI/i;
        complex w = {cos(x), sin(x)};
        for (int j=0; j<len; j+=i<<1){
            complex th = {1,0};
            for (int k=0; k<i; k++){
                complex tmp=complex_mul(th, v[j+k+i]);
                v[j+k+i] = complex_sub(v[j+k], tmp);
                v[j+k] = complex_add(v[j+k], tmp);
                th = complex_mul(th, w);
            }
        }
    }
    if (inv){
        for (int i=0; i<len; i++){
            v[i].real /= len;
            v[i].real = floor(v[i].real + 0.5);
        }
    }
}


cptr mut(cptr a, int len_a){  
    int n = 1;
    while(n < len_a+1) n *= 2;
    n *= 2;
    
    a = (cptr)realloc(a, sizeof(complex) * n);
	memset(a+len_a,0,sizeof(complex)*(n-len_a));
    
    cptr c = (cptr)malloc(sizeof(complex) * n);

    FFT(a, 0, n);

    for(int i=0; i<n; i++){
        c[i] = complex_mul(a[i], a[i]);
    }

    FFT(c, 1, n);

    free(a);
    return c;
}





complex complex_add(complex a, complex b){
    return (complex){a.real + b.real, a.imag + b.imag};
}

complex complex_sub(complex a, complex b){
    return (complex){a.real - b.real, a.imag - b.imag};
}

complex complex_mul(complex a, complex b){
    return (complex){a.real * b.real - a.imag * b.imag, a.real * b.imag + a.imag * b.real};
}

complex complex_div(complex a, complex b){
    return (complex){(a.real * b.real + a.imag * b.imag) / (b.real * b.real + b.imag * b.imag), (a.imag * b.real - a.real * b.imag) / (b.real * b.real + b.imag * b.imag)};
}