#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <malloc.h>




int main(){
	int n,m;
	// scanf("%d%d",&n,&m);
    // n++;
    // m++;
    n=1000000;
    m=1000000;


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
