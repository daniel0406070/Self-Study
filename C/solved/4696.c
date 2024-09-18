#include <stdio.h>

int main(){
    double n;
    while (1){
        scanf("%lf", &n);
        if (n == 0) break;
        printf("%.2lf\n",n*n*n*n+n*n*n+n*n+n+1);
    }
}