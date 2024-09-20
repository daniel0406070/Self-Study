#include <stdio.h>

int main(){
    long long int a,b;
    scanf("%lld %lld", &a, &b);
    long long int c=(a-a/2)*b-(a/2)*b, d = a*(b-b/2)-a*(b/2);

    printf("%lld\n", c>d?d:c);

}