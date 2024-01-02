#include <stdio.h>

int main(){
    int a;
    scanf("%d",&a);

    if(a%100==10) printf("%d", a/100+a%100);
    else printf("%d",a%10+a/10);

}