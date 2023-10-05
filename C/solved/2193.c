#include <stdio.h>

int main(){
    long long int n;
    long long int dp[91][2];
    scanf("%d", &n);

    dp[0][0] = 1;
    dp[0][1] = 1;
    for (int i = 1; i <= n; ++i){
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }

    printf("%lld\n", dp[n-1][1]);
}