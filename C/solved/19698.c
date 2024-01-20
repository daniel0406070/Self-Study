#include <stdio.h>

int main(){
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);

    long long int ans = (b/d)*(c/d);
    if(ans > a) ans = a;

    printf("%d",ans);
}