#include <stdio.h>
#include <math.h>

int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);

    printf("%d\n",(int)floor(1LL*(a+1)*(b+1)/(c+1)-1));
}