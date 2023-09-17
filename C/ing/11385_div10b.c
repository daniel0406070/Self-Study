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

typedef struct tns *tnsptr;
typedef struct tns{
    cptr a[4];
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
            v[i].real = floor(v[i].real + 0.5);
            v[i].imag = floor(v[i].imag + 0.5);
        }
    }
}


tnsptr mut(cptr a1, cptr a2, cptr b1, cptr b2, int len_a , int len_b){  
    int n = 1;
    while(n < len_a+1 || n < len_b+1) n *= 2;
    n *= 2;
    a1 = (cptr)realloc(a1, sizeof(complex) * n);
    a2 = (cptr)realloc(a2, sizeof(complex) * n);
    b1 = (cptr)realloc(b1, sizeof(complex) * n);
    b2 = (cptr)realloc(b2, sizeof(complex) * n);
    memset(a1+len_a, 0, sizeof(complex) * (n - len_a));
    memset(a2+len_a, 0, sizeof(complex) * (n - len_a));
    memset(b1+len_b, 0, sizeof(complex) * (n - len_b));
    memset(b2+len_b, 0, sizeof(complex) * (n - len_b));
    
    cptr c1 = (cptr)malloc(sizeof(complex) * n);
    cptr c2 = (cptr)malloc(sizeof(complex) * n);
    cptr c3 = (cptr)malloc(sizeof(complex) * n);

    FFT(a1, 0, n);
    FFT(a2, 0, n);
    FFT(b1, 0, n);
    FFT(b2, 0, n);

    for(int i=0; i<n; i++){
        c1[i] = complex_mul(a1[i], b1[i]);
        c2[i] = complex_add(complex_mul(a1[i], b2[i]), complex_mul(a2[i], b1[i]));
        c3[i] = complex_mul(a2[i], b2[i]);
    }

    FFT(c1, 1, n);
    FFT(c2, 1, n);
    FFT(c3, 1, n);

    free(a1);
    free(a2);
    free(b1);
    free(b2);

    tnsptr c = (tnsptr)malloc(sizeof(tns));
    c->a[0] = c1;
    c->a[1] = c2;
    c->a[2] = c3;

    return c;
}

int main(){
	int n,m;
	// scanf("%d%d",&n,&m);
    // n++;
    // m++;
    n=1000000;
    m=1000000;

    cptr a1= (cptr)malloc(sizeof(complex) * n);
    cptr a2= (cptr)malloc(sizeof(complex) * n);

    cptr b1= (cptr)malloc(sizeof(complex) * m);
    cptr b2= (cptr)malloc(sizeof(complex) * m);

    int tmp;
    for (int i = 0; i < n; ++i){
        // scanf("%d",&tmp);
        tmp=1000000;
        a1[i].real = tmp&1023;
        tmp>>=10;
        a2[i].real = tmp&1023;
        a1[i].imag = 0;
        a2[i].imag = 0;
    }
    for (int i = 0; i < m; ++i){
        // scanf("%d",&tmp);
        tmp=1000000;
        b1[i].real = tmp&1023;
        tmp>>=10;
        b2[i].real = tmp&1023;
        b1[i].imag = 0;
        b2[i].imag = 0;
    }
    // for (int i = 0; i < n; ++i){
    // 	printf("%d ",(int)a[i].real);
    // }
    // printf("\n");
    // for (int i = 0; i < m; ++i){
    // 	printf("%d ",(int)b[i].real);
    // }
    // printf("\n");

    tns *c = mut(a1, a2, b1, b2, n, m);

    cptr c1 = c->a[0];
    cptr c2 = c->a[1];
    cptr c3 = c->a[2];

    long long int d1=0,d2=0,d3=0;
    
    for (int i = 0; i < n+m-1; ++i){
    	d1^= (long long int)c1[i].real;
        d2^= (long long int)c2[i].real;
        d3^= (long long int)c3[i].real;
    }

    long long int res=d1;
    res+=d2<<10;
    res+=d3<<20;
    
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