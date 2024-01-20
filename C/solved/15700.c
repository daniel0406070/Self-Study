#include <stdio.h> 

int main(){
    long long int a,b;
    scanf("%lld %lld",&a,&b);
    
    long long int ans=a*b;
    ans/=2;

    printf("%lld",ans);
}