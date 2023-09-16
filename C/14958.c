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

char ac[100002];
char bc[100002];
char rps[3]={'R','P','S'};
char rps2[3]={'P','S','R'};



int main(){
	int n,m;
	scanf("%d%d",&n,&m);

	scanf("%s",ac);
	scanf("%s",bc);
	
	int win[200007]={0};
	int max=0;
	for (int i = 0; i < 3; ++i){
		cptr a = (cptr)malloc(sizeof(complex) * (n+4));
		cptr b = (cptr)malloc(sizeof(complex) * (m+4));
		for (int j = 0; j < n; ++j){
			if(rps[i]==ac[j]) a[j].real = 1;
			else a[j].real = 0;
			a[i].imag = 0;
		}
		for (int j = 0; j < m; ++j){
			if(rps2[i]==bc[j]) b[m-j-1].real = 1;
			else b[m-j-1].real = 0;
			b[i].imag = 0;
			
		}

		cptr c = mut(a,b,n,m);

		// print(c,n+m-1);

		
		int max=0;
		for (int j = 0; j < n+m-1; ++j){
			win[j]+=c[j].real;
		}
		free(c);
	}
	for (int i = m-1; i < n+m-1; ++i){
		if(win[i]>max) max=win[i];
	}
	printf("%d\n",max);
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


// 가위바위보를 한거를 하나로 모으기 위해서 
// 1-1 2-2 3-3을 1-3 2-2 3-1로 배치해서 4로 접근할수있게 한다
// 내가 RPS인 경우를 3번 계산한다
