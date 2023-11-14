#include <stdio.h>
#include <math.h>

int main(){
    int s,e;
    scanf("%d %d",&s,&e);

    s--;
    int a=(-1+sqrt(1+8*s))/2,b=(-1+sqrt(1+8*e))/2;

    int sum=0;
    
    sum+=b*(b+1)*(2*b+1)/6+(b+1)*(e-b*(b+1)/2);
    sum-=a*(a+1)*(2*a+1)/6+(a+1)*(s-a*(a+1)/2);

    printf("%d",sum);
}
