#include <stdio.h>

int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);

    printf("%lld",(long long int)((a/c)+(a%c>0))*((b/c)+(b%c>0)));
}