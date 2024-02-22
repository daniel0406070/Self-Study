#include <stdio.h>
#include <math.h>

int main(){
    int n;
    scanf("%d", &n);

    long long int a = 2;
    for(int i = 0; i < n; i++){
        a += pow(2, i);
    }

    printf("%lld", a*a);
}
