#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int dp[10001] = {0, };
    int wine[10001] = {0, };

    for(int i=1; i<=n; i++){
        scanf("%d", &wine[i]);
    }

    dp[1] = wine[1];
    dp[2] = wine[1] + wine[2];

    for(int i=3; i<=n; i++){
        int max = dp[i-1];
        if(dp[i-2] + wine[i] > max) max = dp[i-2] + wine[i];
        if(dp[i-3] + wine[i-1] + wine[i] > max) max = dp[i-3] + wine[i-1] + wine[i];
        dp[i] = max;
    }

    printf("%d\n", dp[n]);www
}