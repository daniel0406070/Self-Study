#include <stdio.h>

int dp[41]={0,};
int req[41]={0,};

int main(){
    int n;
    scanf("%d", &n);

    dp[0]=1;
    dp[1]=1;
    req[0]=1;
    req[1]=1;
    for(int i=2; i<n; i++){
        dp[i]=dp[i-1]+1;
        req[i]=req[i-1]+req[i-2];
    }

    printf("%d %d\n", req[n-1], dp[n-2]);
}