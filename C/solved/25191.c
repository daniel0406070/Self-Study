#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);

    int a,b;
    scanf("%d %d",&a,&b);

    int ans = a/2+b;
    if(ans>n) ans = n;

    printf("%d\n",ans);    
}