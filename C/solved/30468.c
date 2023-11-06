#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



int main(){
    int a,b,c,d,e,n;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &n);

    e=4*n-(a+b+c+d);
    if (e<0){
        e=0;
    }

    printf("%d", e);

} 