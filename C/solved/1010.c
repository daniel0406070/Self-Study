#include <stdio.h>

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int dp[31][31] = {0, };
        int n, m;
        scanf("%d %d", &n, &m);

        for(int i=0; i<=m; i++){
            dp[1][i] = i;
        }
        for(int i=2; i<=n; i++){
            for(int j=i; j<=m; j++){
                for(int k=j; k>=i; k--){
                    dp[i][j] += dp[i-1][k-1];
                }
            }
        }

        printf("%d\n", dp[n][m]);
    }
}