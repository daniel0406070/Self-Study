#include <stdio.h>

int main(){
    long double a = 0.1L;
    a=a*a;
    printf("%0.30Lf\n",a*a);
}