#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <malloc.h>

#define size 1000
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

void swap(complex *a, complex *b);
void FFT(cptr v,int inv, int len);
void mut(cptr a, cptr b, cptr c);

int compare(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}



int main(){
    int n,k;
    scanf("%d %d", &n, &k);

    int *a = (int*)malloc(sizeof(int) * n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), compare);

    int d2 = 0;
    while((1<<d2) <= k) d2++;
    cptr c[d2];


    c[0] = (cptr)malloc(sizeof(complex) * size);
    memset(c[0], 0, sizeof(complex) * size);
    for(int i=0; i<n; i++){
        c[0][a[i]].real = 1;
    }

    FFT(c[0], 0, size);
    for(int i=1; i<d2; i++){
        c[i] = (cptr)malloc(sizeof(complex) * size);
        mut(c[i-1], c[i-1],c[i]);
    }

    cptr ans = (cptr)malloc(sizeof(complex) * size);
    memset(ans, 0, sizeof(complex) * size);
    ans[0].real = 1;

    for(int i=0; i<d2; i++){
        if(k & (1<<i)){
            mut(ans, c[i], ans);
        }
    }
    FFT(ans, 1, size);

    for(int i=0; i<size; i++){
        if(ans[i].real > 0.5){
            printf("%d ", i);
        }
    }

    free(a);
    for(int i=0; i<d2; i++){
        free(c[i]);
    }
    free(ans);
    return 0;
}



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

void mut(cptr a, cptr b, cptr c){ 
    for(int i=0; i<size; i++){
        c[i] = complex_mul(a[i], b[i]);
    }
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