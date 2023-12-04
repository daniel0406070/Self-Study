#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <malloc.h>

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


cptr mut(cptr a, int len_a, cptr b, int len_b){
    int n = 1;
    while(n < len_a+1 || n < len_b+1) n *= 2;
    n *= 2;
    
    a=(cptr)realloc(a,sizeof(complex)*n);
    memset(a+len_a,0,sizeof(complex)*(n-len_a));
    b=(cptr)realloc(b,sizeof(complex)*n);
    memset(b+len_b,0,sizeof(complex)*(n-len_b));
    
    cptr c = (cptr)malloc(sizeof(complex) * n);
    
    FFT(a, 0, n);
    FFT(b, 0, n);

    for(int i=0; i<n; i++){
        c[i] = complex_mul(a[i], b[i]);
    }

    FFT(c, 1, n);

    for(int i=0; i<n; i++){
        c[i].real = (long long int)floor(c[i].real + 0.5)%100003;
        c[i].imag = 0;
    }

    free(a);
    free(b);
    return c;
}


int main(){
    int n,q;
    scanf("%d",&n);

    cptr *a = (cptr *)malloc(sizeof(cptr)*n);
    for(int i=0;i<n;i++){
        a[i] = (cptr)malloc(sizeof(complex)*2);
        scanf("%Lf",&a[i][1].real);
        a[i][1].imag = 0;
        a[i][0] = (complex){1,0};
    }

    int count = n;
    int len = 2;

    while(count > 1){
        for(int i=0;i<count;i+=2){
            if(i+1==count){
                a[i/2] = a[i];
                a[i/2] = (cptr)realloc(a[i/2],sizeof(complex)*len*2-1);
                memset(a[i/2]+len,0,sizeof(complex)*(len-1));
                break;
            }
            a[i/2] = mut(a[i],len,a[i+1],len);
        }

        count = (count+1)/2;
        len = len*2-1;

        // for(int i=0;i<count;i++){
        //     for(int j=0;j<len;j++){
        //         printf("%d ",(int)a[i][j].real);
        //     }
        //     printf("\n");
        // }

    }


    scanf("%d",&q);
    int k;
    for(int i=0;i<q;i++){
        scanf("%d",&k);
        printf("%d\n",(int)a[0][k].real);
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