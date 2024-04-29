#include <stdio.h>

long long gcd (long long a, long long b){
    if(b==0) return a;
    return gcd(b, a%b);
}

int main(){
    long long a,b,c;
    scanf("%lld %lld", &a, &b);

    c=a*b;
    printf("%lld\n", c/gcd(a,b));
}