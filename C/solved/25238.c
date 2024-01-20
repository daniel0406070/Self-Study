#include <stdio.h>

int main(){
    int a,b;
    scanf("%d %d",&a,&b);
   
    double c = a-a*(double)b/100;
    printf("%c",c>=100?'0':'1');
}