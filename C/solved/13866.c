#include <stdio.h>

int main(){
    int a,b,c,d;
    scanf("%d %d %d %d",&a, &b, &c, &d);

    int ans=a+d-b-c;
    ans=ans>0?ans:-1*ans;

    printf("%d",ans);
}