#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char A[1002];
    char B[1002];
    char C[1002];
    scanf("%s", A);
    scanf("%s", B);
    scanf("%s", C);

    int lenA = strlen(A);
    int lenB = strlen(B);
    int lenC = strlen(C);

    int dp[lenA+1][lenB+1][lenC+1];
    memset(dp, 0, sizeof(dp));

    int max = 0;
    for(int i=1; i<=lenA; i++){
        for(int j=1; j<=lenB; j++){
            for(int k=1; k<=lenC; k++){
                if(A[i-1] == B[j-1] && B[j-1] == C[k-1]) dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                else {
                    max=0;
                    max=dp[i-1][j][k] > dp[i][j-1][k]?dp[i-1][j][k]:dp[i][j-1][k];
                    dp[i][j][k] = max > dp[i][j][k-1]?max:dp[i][j][k-1];
                }
            }
        }
    }
    
    printf("%d\n", dp[lenA][lenB][lenC]);
}
