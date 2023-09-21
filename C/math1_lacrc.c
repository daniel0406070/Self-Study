#include <stdio.h>
#include <math.h>
const double PI=acos(-1.0L);

double fn(double x, double a){
    return 4*PI*pow(a+x,2)*x/((4*PI*pow(a+x,3)-4*PI*pow(a,3))/3L);
}

int main(){
    double i=0L;
    while(i<=0.1L){
        printf("f(%lF) = %lf\n", i, fn(i,21)-1);
        i+=0.001L;
    }
}

// 0.05에서 예상 0.0024 오차가 발생
// 계산결과 0.002379이다