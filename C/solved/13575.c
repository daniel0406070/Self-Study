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

void swap(complex *a, complex *b);
void FFT(cptr v,int inv, int len);

int compare(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}


int main(){
    int n,k;
    scanf("%d %d", &n, &k);

    int a[1001];
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), compare);

    int d2 = 0;
    while((1<<d2) <= k) d2++;
    int len=1048576;

    cptr c=(cptr)malloc(sizeof(complex) * len);
    memset(c, 0, sizeof(complex) * len);
    for(int i=0; i<n; i++){
        c[a[i]].real = 1;
    }

    cptr ans=(cptr)malloc(sizeof(complex) * len);
    memset(ans, 0, sizeof(complex) * len);
    ans[0].real = 1;

    
    for(int i=0; i<d2; i++){
        FFT(c, 0, len);
    
        if(k & (1<<i)){
            FFT(ans, 0, len);
            for(int j=0; j<len; j++){
                ans[j] = complex_mul(ans[j], c[j]);
            }
            FFT(ans, 1, len);
        }

        for(int j=0; j<len; j++){
            c[j] = complex_mul(c[j], c[j]);
        }
        FFT(c, 1, len);
    }

    for(int i=0; i<len; i++){
        if(ans[i].real > 0.5){
            printf("%d ", i);
        }
    }

    free(c);
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
            v[i].imag /= len;
            v[i].real = floor(v[i].real + 0.5);
            v[i].imag = floor(v[i].imag + 0.5);
            if(v[i].real) v[i].real = 1;
            else v[i].real = 0;
            if(v[i].imag) v[i].imag = 1;
            else v[i].imag = 0;
        }
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