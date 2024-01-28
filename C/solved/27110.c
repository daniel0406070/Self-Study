#include <stdio.h>

int main(){
    int n,a,b,c;
    scanf("%d",&n);
    scanf("%d %d %d",&a,&b,&c);

    a = a>n?n:a;
    b = b>n?n:b;
    c = c>n?n:c;

    printf("%d",a+b+c);
}