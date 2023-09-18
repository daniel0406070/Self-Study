#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <malloc.h>
#define test 0

const double PI = acos(-1.L);

typedef struct complex *cptr;
typedef struct complex{
    long double real;
    long double imag;
}complex;

typedef struct tns *tnsptr;
typedef struct tns{
    cptr v[4];
}tns;

complex complex_add(complex a, complex b);
complex complex_sub(complex a, complex b);
complex complex_mul(complex a, complex b);
complex complex_div(complex a, complex b);

void FFT(cptr v,int inv, int len){
    for (unsigned int s = 2; s <= len; s *= 2) {
        complex w[s/2];
        for (unsigned int i = 0; i < s/2; i++) {
            long double t = 2*PI*i/s * (inv? -1 : 1);
            w[i] = (complex){cos(t), sin(t)};
        }
        for (unsigned int i = 0; i < len; i += s) {
            for (unsigned int j = 0; j < s/2; j++) {
                complex tmp = complex_mul(v[i + j + s/2], w[j]);
                v[i + j + s/2] = complex_sub(v[i + j], tmp);
                v[i + j] = complex_add(v[i + j],tmp);
            }
        }
    }
    if (inv)
        for (unsigned int i = 0; i < len; i++)
            v[i] /= len;
}
