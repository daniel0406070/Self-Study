#include <stdio.h>
#include <math.h>

double fn(double x){
    return -sqrt(x+3)+(7L+x)/4L;
}

int main(){
    double i=1L;
    while(i<1.5L){
        printf("f(%lF) = %lf\n", i, fn(i)/(i-1L));
        i+=0.001L;
    }
}