#include <stdio.h>

int main(){
    int a,b;
    scanf("%d %d",&a,&b);

    if(a==0 && b==0)
        printf("Not a moose\n");
    else

    if(a>b)
        printf("Odd %d\n",a*2);
    else if(a<b)
        printf("Odd %d\n",b*2);
    else
        printf("Even %d\n",a+b);

    return 0;
}