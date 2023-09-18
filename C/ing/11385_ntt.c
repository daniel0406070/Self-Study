#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <malloc.h>
#include <stdbool.h>
#define test 0

// const int A = 119, B = 23, P = A << B | 1, R = 3;

int crt(int x, int y, int p1, int p2, int r1, int r2){
    int x = (long long)a * d % P * 119 % P;
    int y = (long long)b * c % P * 119 % P;
    return (x + y) % P;
}

int Pow(int x, int y, int P) {
    int r = 1;
    while (y) {
        if (y & 1) r = (long long)r * x % P;
        x = (long long)x * x % P;
        y >>= 1;
    }
    return r;
}
 
long long int* FFT(long long int tmp_a[], bool f, int N, int P, int R) {
    long long int *a = (long long int*)malloc(sizeof(long long int)*N);
    for(int i=0; i<N; i++){
        a[i]=tmp_a[i];
    }
    int i, j, k, x, y, z;
    j = 0;
    for (i = 1; i < N; i++) {
        for (k = N >> 1; j >= k; k >>= 1) j -= k;
        j += k;
        if (i < j) {
            k = a[i];
            a[i] = a[j];
            a[j] = k;
        }
    }
    for (i = 1; i < N; i <<= 1) {
        x = Pow(f ? Pow(R, P - 2,P) : R, P / i >> 1, P);
        for (j = 0; j < N; j += i << 1) {
            y = 1;
            for (k = 0; k < i; k++) {
                z = (long long)a[i | j | k] * y % P;
                a[i | j | k] = a[j | k] - z;
                if (a[i | j | k] < 0) a[i | j | k] += P;
                a[j | k] += z;
                if (a[j | k] >= P) a[j | k] -= P;
                y = (long long)y * x % P;
            }
        }
    }
    if (f) {
        j = Pow(N, P - 2, P);
        for (i = 0; i < N; i++) a[i] = (long long)a[i] * j % P;
    }
    return a;
}

long long int* mut(long long int a[], long long int b[], int n){  

    int A1 = 119, B1 = 23, P1 = A1 << B1 | 1, R1 = 3;
    long long int* tmp_a = FFT(a, 0, n, P1, R1);
    long long int* tmp_b = FFT(b, 0, n, P1, R1);

    long long int *c1 = (long long int*)malloc(sizeof(long long int)*n);
    for(int i=0; i<n; i++){
        c1[i] = (long long)tmp_a[i] * tmp_b[i] % P1;
    }
    FFT(c1, 1, n, P1, R1);


    A1 = 5, B1 = 25, P1 = A1 << B1 | 1, R1 = 3;
    tmp_a = FFT(a, 0, n, P1, R1);
    tmp_b = FFT(b, 0, n, P1, R1);

    long long int *c2 = (long long int*)malloc(sizeof(long long int)*n);
    for(int i=0; i<n; i++){
        c2[i] = (long long)tmp_a[i] * tmp_b[i] % P1;
    }
    FFT(c2, 1, n, P1, R1);

    

    long long int *c = (long long int*)malloc(sizeof(long long int)*n);

    for(int i=0; i<n; i++){
        printf("%lld %lld\n",c1[i],c2[i]);
    }



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

    int len=1;
    while(len < n+1 || len < m+1) len *= 2;
    len *= 2;

    long long int *a = (long long int*)malloc(sizeof(long long int)*(len));
    long long int *b = (long long int*)malloc(sizeof(long long int)*(len));

    int tmp;
    for (int i = 0; i < n; ++i){
        if(test) scanf("%d",&tmp);
        else tmp=1000000;
        a[i] = tmp;
    }
    for (int i = 0; i < m; ++i){
        if(test) scanf("%d",&tmp);
        else tmp=1000000;
        b[i] = tmp;
    }

    long long int* c = mut(a,b,len);

    for(int i=0; i<n+m-1; i++){
        printf("%lld ",c[i]);
    }
    printf("\n");

    unsigned long long int res=0;
    for (int i = 0; i < n+m-1; ++i){
        res ^= c[i];
    }

    printf("%lld\n",res);

    free(a);
    free(b);
    return 0;
}
