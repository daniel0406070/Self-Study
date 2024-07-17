#include <stdio.h>

int main(){
    long long int a,b,c,d;
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
    long long int max, min;

    if(c-d>=a-1){
        max = a;
    
    }else{
        max = c-d+1;
    }

    if ((c-d)%b==0){
        min = (c-d)/b+1;
    }else{
        min = (c-d)/b+2;
    }

    printf("%lld %lld", max, min);
}