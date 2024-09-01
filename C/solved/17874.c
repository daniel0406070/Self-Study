#include <stdio.h>

int main(){
    int n,h,w;
    scanf("%d %d %d",&n,&h,&w);

    h=n-h>h?n-h:h;
    w=n-w>w?n-w:w;

    printf("%d",h*w*4);
}