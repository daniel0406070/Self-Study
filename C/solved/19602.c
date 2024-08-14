#include <stdio.h>

int main(){
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);

    int sum = a+b*2+c*3;
    if(sum >= 10) printf("happy");
    else printf("sad");
}