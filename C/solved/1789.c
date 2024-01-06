#include <stdio.h>
#include <math.h>


int main(){
    long long int s;
    scanf("%lld",&s);

    printf("%d", (int)(sqrt(0.25+2*s)-0.5));
}