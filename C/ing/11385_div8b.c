#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <malloc.h>
#define test 0

const double PI = acos(-1);

typedef struct complex *cptr;
typedef struct complex{
    long double real;
    long double imag;
}complex;

typedef struct tns *tnsptr;
typedef struct tns{
    cptr a[5];
}tns;

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
            v[i].imag /= len;
            v[i].real = floor(v[i].real+0.5);
            v[i].imag = floor(v[i].imag+0.5);
        }
    }
}


tnsptr mut(cptr a1, cptr a2, cptr a3, cptr b1, cptr b2, cptr b3, int len_a , int len_b){  
    int n = 1;
    while(n < len_a+1 || n < len_b+1) n *= 2;
    n *= 2;
    a1 = (cptr)realloc(a1, sizeof(complex) * n);
    a2 = (cptr)realloc(a2, sizeof(complex) * n);
    a3 = (cptr)realloc(a3, sizeof(complex) * n);
    b1 = (cptr)realloc(b1, sizeof(complex) * n);
    b2 = (cptr)realloc(b2, sizeof(complex) * n);
    b3 = (cptr)realloc(b3, sizeof(complex) * n);
    memset(a1+len_a, 0, sizeof(complex) * (n - len_a));
    memset(a2+len_a, 0, sizeof(complex) * (n - len_a));
    memset(a3+len_a, 0, sizeof(complex) * (n - len_a));
    memset(b1+len_b, 0, sizeof(complex) * (n - len_b));
    memset(b2+len_b, 0, sizeof(complex) * (n - len_b));
    memset(b3+len_b, 0, sizeof(complex) * (n - len_b));
    
    cptr c1 = (cptr)malloc(sizeof(complex) * n);
    cptr c2 = (cptr)malloc(sizeof(complex) * n);
    cptr c3 = (cptr)malloc(sizeof(complex) * n);
    cptr c4 = (cptr)malloc(sizeof(complex) * n);
    cptr c5 = (cptr)malloc(sizeof(complex) * n);

    FFT(a1, 0, n);
    FFT(a2, 0, n);
    FFT(a3, 0, n);
    FFT(b1, 0, n);
    FFT(b2, 0, n);
    FFT(b3, 0, n);

    for(int i=0; i<n; i++){
        c1[i] = complex_mul(a1[i], b1[i]);
        c2[i] = complex_add(complex_mul(a1[i], b2[i]), complex_mul(a2[i], b1[i]));
        c3[i] = complex_add(complex_mul(a1[i], b3[i]), complex_mul(a3[i], b1[i]));
        c3[i] = complex_add(c3[i], complex_mul(a2[i], b2[i]));
        c4[i] = complex_add(complex_mul(a2[i], b3[i]), complex_mul(a3[i], b2[i]));
        c5[i] = complex_mul(a3[i], b3[i]);
    }

    free(a1);
    free(a2);
    free(a3);
    free(b1);
    free(b2);
    free(b3);

    FFT(c1, 1, n);
    FFT(c2, 1, n);
    FFT(c3, 1, n);
    FFT(c4, 1, n);
    FFT(c5, 1, n);


    tnsptr c = (tnsptr)malloc(sizeof(tns));
    c->a[0] = c1;
    c->a[1] = c2;
    c->a[2] = c3;
    c->a[3] = c4;
    c->a[4] = c5;

    return c;
}

int main(){
	int n,m;
    if(test){
        scanf("%d%d",&n,&m);
        n++;
        m++;
    }
    else{
        n=1000000;
        m=1000000;
    }

    cptr a1= (cptr)malloc(sizeof(complex) * n);
    cptr a2= (cptr)malloc(sizeof(complex) * n);
    cptr a3= (cptr)malloc(sizeof(complex) * n);

    cptr b1= (cptr)malloc(sizeof(complex) * m);
    cptr b2= (cptr)malloc(sizeof(complex) * m);
    cptr b3= (cptr)malloc(sizeof(complex) * m);

    int tmp;
    for (int i = 0; i < n; ++i){
        if(test) scanf("%d",&tmp);
        else tmp=1000000;
        a1[i].real = tmp&255;
        tmp>>=8;
        a2[i].real = tmp&255;
        tmp>>=8;
        a3[i].real = tmp&255;
        a1[i].imag = 0;
        a2[i].imag = 0;
        a3[i].imag = 0;
    }
    for (int i = 0; i < m; ++i){
        if(test) scanf("%d",&tmp);
        else tmp=1000000;
        b1[i].real = tmp&255;
        tmp>>=8;
        b2[i].real = tmp&255;
        tmp>>=8;
        b3[i].real = tmp&255;
        b1[i].imag = 0;
        b2[i].imag = 0;
        b3[i].imag = 0;
    }

    tns *c = mut(a1, a2, a3, b1, b2, b3, n, m);

    cptr c1 = c->a[0];
    cptr c2 = c->a[1];
    cptr c3 = c->a[2];
    cptr c4 = c->a[3];
    cptr c5 = c->a[4];

    unsigned long long int d1=0,d2=0,d3=0,d4=0,d5=0;
    
    for (int i = 0; i < n+m-1; ++i){
    	d1^= (unsigned long long int)c1[i].real;
        d2^= (unsigned long long int)c2[i].real;
        d3^= (unsigned long long int)c3[i].real;
        d4^= (unsigned long long int)c4[i].real;
        d5^= (unsigned long long int)c5[i].real;
    }

    unsigned long long int res=d1;
    res+=d2<<8;
    res+=d3<<16;
    res+=d4<<24;
    res+=d5<<32;
    
    printf("%lld\n",res);

    free(c);
    return 0;
	
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