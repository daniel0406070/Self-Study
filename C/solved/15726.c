#include <stdio.h>
#include <math.h>

int main(){
    double ans1=1,ans2=1;
    double a,b,c;
    scanf("%lf %lf %lf",&a,&b,&c);

    ans1=a/b*c;
    ans2=a/c*b;

    if(ans1>ans2) printf("%d", (int)floor(ans1));
    else printf("%d", (int)floor(ans2));
}