#include <stdio.h>

int main(){
    int a,b,n;
    scanf("%d %d",&a,&b);
    scanf("%d",&n);

    if(a+b>=n*2) printf("%d",a+b-2*n);
    else printf("%d",a+b);
}