#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    long long int sum = 0;
    for(long long int i = 1; i < n; i++){
        sum += i * n + i;
    }

    printf("%lld\n", sum);
}