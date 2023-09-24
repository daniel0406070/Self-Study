#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <malloc.h>

const double PI = acos(-1);

typedef struct complex *cptr;const double PI = acos(-1);

typedef struct complex *cptr;
typedef struct complex{
    double real;
    double imag;
}complex;

complex complex_add(complex a, complex b);
complex complex_sub(complex a, complex b);
complex complex_mul(complex a, complex b);
complex complex_div(complex a, complex b);

void FFT(cptr v,complex w, int len){ 
    if (len == 1) return;

    cptr v_odd= (cptr)malloc(sizeof(complex) * len/2);
    cptr v_even= (cptr)malloc(sizeof(complex) * len/2);

    for(int i=0; i<len; i++){
        (i % 2? v_odd : v_even)[i/2] = v[i];
    }

    FFT(v_odd, complex_mul(w, w), len/2);
    FFT(v_even, complex_mul(w, w), len/2);

    complex wp={1,0};
    for(int i=0; i<len/2; i++){
        v[i] = complex_add(v_even[i], complex_mul(wp, v_odd[i]));
        v[i+len/2] = complex_sub(v_even[i], complex_mul(wp, v_odd[i]));
        wp = complex_mul(wp, w);
    }

    free(v_odd);
    free(v_even);

}

cptr mut(cptr a, cptr b, int len_a , int len_b){  
    int n = 1;
    while(n < len_a+1 || n < len_b+1) n *= 2;
    n *= 2;
    a = (cptr)realloc(a, sizeof(complex) * n);
    b = (cptr)realloc(b, sizeof(complex) * n);
    
    cptr c = (cptr)malloc(sizeof(complex) * n);

    complex w = {cos(2*PI/n), sin(2*PI/n)};

    FFT(a, w, n);
    FFT(b, w, n);

    for(int i=0; i<n; i++){
        c[i] = complex_mul(a[i], b[i]);
    }


    complex ww={1,0};
    FFT(c, complex_div(ww, w), n);
    for(int i=0; i<n; i++){
        c[i].real /= n;
        c[i].imag /= n;
        c[i].real = floor(c[i].real + 0.5);
        c[i].imag = floor(c[i].imag + 0.5);
    }
    free(a);
    free(b);
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
typedef struct complex{
    double real;
    double imag;
}complex;

complex complex_add(complex a, complex b);
complex complex_sub(complex a, complex b);
complex complex_mul(complex a, complex b);
complex complex_div(complex a, complex b);

void FFT(cptr v,complex w, int len){ 
    if (len == 1) return;

    cptr v_odd= (cptr)malloc(sizeof(complex) * len/2);
    cptr v_even= (cptr)malloc(sizeof(complex) * len/2);

    for(int i=0; i<len; i++){
        (i % 2? v_odd : v_even)[i/2] = v[i];
    }

    FFT(v_odd, complex_mul(w, w), len/2);
    FFT(v_even, complex_mul(w, w), len/2);

    complex wp={1,0};
    for(int i=0; i<len/2; i++){
        v[i] = complex_add(v_even[i], complex_mul(wp, v_odd[i]));
        v[i+len/2] = complex_sub(v_even[i], complex_mul(wp, v_odd[i]));
        wp = complex_mul(wp, w);
    }

    free(v_odd);
    free(v_even);

}

cptr mut(cptr a, cptr b, int len_a , int len_b){  
    int n = 1;
    while(n < len_a+1 || n < len_b+1) n *= 2;
    n *= 2;
    a = (cptr)realloc(a, sizeof(complex) * n);
    b = (cptr)realloc(b, sizeof(complex) * n);
    
    cptr c = (cptr)malloc(sizeof(complex) * n);

    complex w = {cos(2*PI/n), sin(2*PI/n)};

    FFT(a, w, n);
    FFT(b, w, n);

    for(int i=0; i<n; i++){
        c[i] = complex_mul(a[i], b[i]);
    }


    complex ww={1,0};
    FFT(c, complex_div(ww, w), n);
    for(int i=0; i<n; i++){
        c[i].real /= n;
        c[i].imag /= n;
        c[i].real = floor(c[i].real + 0.5);
        c[i].imag = floor(c[i].imag + 0.5);
    }
    free(a);
    free(b);
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