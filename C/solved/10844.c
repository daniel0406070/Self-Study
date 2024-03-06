#include <stdio.h>

int dp[101][10];

int main(){
    int n;
    scanf("%d", &n);

    for(int i=0; i<=9; i++){
        dp[1][i]=1;
    }

    for(int i=2; i<=n; i++){
        dp[i][0]=dp[i-1][1];
        dp[i][0]%=1000000000;

        for(int j=1; j<9; j++){
            dp[i][j]=dp[i-1][j-1];
            dp[i][j]+=dp[i-1][j+1];
            dp[i][j]%=1000000000;
        }

        dp[i][9]=dp[i-1][8];
        dp[i][9]%=1000000000;
    }

    int sum=0;

    for(int i=1; i<=9; i++){
        sum+=dp[n][i];
        sum%=1000000000;
    }
    printf("%d", sum);
}