#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);

    if(n%10!=0){
        printf("-1");
        return 0;
    }

    int a,b,c;

    a=n/300;
    n%=300;
    b=n/60;
    n%=60;
    c=n/10;

    printf("%d %d %d",a,b,c);
}