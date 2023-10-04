#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, arr[100002];
    int dp[100002];
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    dp[0] = arr[0];
    for(int i=1;i<n;i++){
        if (dp[i-1] > 0) dp[i] = dp[i-1] + arr[i];
        else if (dp[i-1]>arr[i]) dp[i] = dp[i-1];
        else dp[i] = arr[i];
    }

    int max = -2001;
    for(int i=0;i<n;i++) max=max>dp[i]?max:dp[i];
    printf("%d",max);
}