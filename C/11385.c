#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <malloc.h>
#define test 1

const long double PI = acosl(-1.L);

typedef struct complex *cptr;
typedef struct complex{
    long double real;
    long double imag;
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

complex w[1048577];

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
	memset(a+len_a,0,sizeof(complex)*(n-len_a));
	memset(b+len_b,0,sizeof(complex)*(n-len_b));
    
    cptr c = (cptr)malloc(sizeof(complex) * n);

    FFT(a, 0, n);
    FFT(b, 0, n);

    for(int i=0; i<n; i++){
        c[i] = complex_mul(a[i], b[i]);
    }

    FFT(c, 1, n);

    return c;
}

int main(){
	int n,m;
	if(test){
        scanf("%d %d",&n,&m);
        n++;
        m++;
    }
    else{
        n=1000000;
        m=n;
    }

    cptr a = (cptr)malloc(sizeof(complex) * n);
    cptr b = (cptr)malloc(sizeof(complex) * m);

    int tmp;
    for (int i = 0; i < n; ++i){
    	if(test) scanf("%d",&tmp);
        else tmp=1000000;
        a[i].real = tmp;
        a[i].imag = 0;
    }
    for (int i = 0; i < m; ++i){
    	if(test) scanf("%d",&tmp);
        else tmp=1000000;
        b[i].real = tmp;
        b[i].imag = 0;
    }

    cptr c=mut(a,b,n,m);

    unsigned long long res=0;
    for (int i = 0; i < n+m-1; ++i){
    	res^=(unsigned long long)(c[i].real + (c[i].real > 0? 0.5L: -0.5L));
    }
    printf("%lld\n",res);

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


// long double을 사용하면 그냥 풀리는 문제였다.
// 정석은 따로 있는거 같은데 시간날때 시도 해봄