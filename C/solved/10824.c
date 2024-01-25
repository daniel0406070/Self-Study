#include <stdio.h>
#include <math.h>

int main(){
    long long a,b,c,d;
    scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
    printf("%lld",a*(long long)pow(10,floor(log10(b))+1)+b+c*(long long)pow(10,floor(log10(d))+1)+d);
}