#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    
    long long int a = n*(n+1)/2;
    printf("%lld\n", a);
    printf("%lld\n", a*a);
    printf("%lld\n", a*a);

}