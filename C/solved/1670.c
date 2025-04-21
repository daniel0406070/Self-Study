#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d",&n);

    n/=2;

    long long int* dp = (long long int*)malloc((n+1)*sizeof(long long int));

    dp[0] = 1;
    dp[1] = 1;

    for(int i=2; i<=n; i++){
        dp[i] = 0;
        for(int j=0; j<i; j++){
            dp[i] += dp[j] * dp[i-j-1] % 987654321;
        }
        dp[i] %= 987654321;
    }

    printf("%lld\n", dp[n]);
    free(dp);
}