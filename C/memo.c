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

void FFT(cptr v,int inv, int len){
    for(int i=1, j=0; i<len; i++){
        int bit = len>>1;
        while (!((j ^= bit) & bit)) bit >>= 1;
        if (i < j) {
            swap(&v[i], &v[j]);
        }
    }
    for (unsigned int s = 2; s <= len; s *= 2) {
        for (unsigned int i = 0; i < s/2; i++) {
            long double t = 2*PI*i/s * (inv? -1 : 1);
            w[i] = (complex){cosl(t), sinl(t)};
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
        for (unsigned int i = 0; i < len; i++){
            v[i].real /= len;
            v[i].imag /= len;
        }

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

int compare(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int main(){
    
    int n;
    scanf("%d", &n);
    int* tmp=(int*)malloc(sizeof(int) * n);
    for(int i=0; i<n; i++){
        scanf("%d", &tmp[i]);
    }
    qsort(tmp, n, sizeof(int), compare);

    int tn=tmp[n-1]+1;

    cptr a = (cptr)malloc(sizeof(complex) * tn);
    cptr b = (cptr)malloc(sizeof(complex) * tn);
    
    a[0].real = 1;
    for(int i=0; i<n; i++){
        a[tmp[i]].real = 1;

    }
    memcpy(b, a, sizeof(complex) * tn);

    cptr c = mut(a, b, tn, tn);

    int check, cnt=0;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &check);
        if(check<=2*tn-1&&c[check].real != 0) cnt++;
    }
    printf("%d", cnt);

    free(c);
    free(tmp);
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