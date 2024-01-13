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

int len=0;

cptr mut(cptr a, cptr b, int len_a , int len_b){  
    int n = 1;
    while(n < len_a+1 || n < len_b+1) n *= 2;
    n *= 2;
    a = (cptr)realloc(a, sizeof(complex) * n);
    b = (cptr)realloc(b, sizeof(complex) * n);
    
    cptr c = (cptr)malloc(sizeof(complex) * n);

    FFT(a, 0, n);
    FFT(b, 0, n);

    for(int i=0; i<n; i++){
        c[i] = complex_mul(a[i], b[i]);
    }

    FFT(c, 1, n);

    free(a);
    free(b);
    len=n;
    return c;
}

char a[500002], b[500002];
cptr a_rev, b_org;
cptr c;

int main(){
    scanf("%s", a);
    scanf("%s", b);

    int len_a = strlen(a);
    int len_b = strlen(b);
    a_rev = (cptr)malloc(sizeof(complex) * len_a);
    b_org = (cptr)malloc(sizeof(complex) * 2 * len_b);

    for(int i=0; i<len_a; i++){
        a_rev[i].real = a[len_a - i - 1]-'0';
        a_rev[i].imag = 0;
    }
    for(int i=0; i<len_b; i++){
        b_org[i].real = b[i]-'0';
        b_org[i].imag = 0;
    }
    for(int i=len_b; i<2*len_b-1; i++){
        b_org[i].real = b[i-len_b]-'0';
        b_org[i].imag = 0;
    }

    c= mut(a_rev, b_org, len_a, len_b);

    long long int max = 0;
    for(int i=0; i<len; i++){
        if(max < (long long int)c[i].real) max = (long long int)c[i].real;
    }

    printf("%lld", max);
    free(c);
    
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