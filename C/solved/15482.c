#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char A[3009];
    char B[3009];
    scanf("%s", A);
    scanf("%s", B);

    int lenA = strlen(A)/3;
    int lenB = strlen(B)/3;

    int dp[lenA+1][lenB+1];
    memset(dp, 0, sizeof(dp));

    for(int i=1; i<=lenA; i++){
        for(int j=1; j<=lenB; j++){
            if(A[3*i-3] == B[3*j-3] && A[3*i-2] == B[3*j-2] && A[3*i-1] == B[3*j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = dp[i-1][j] > dp[i][j-1]?dp[i-1][j]:dp[i][j-1];
        }
    }
    
    printf("%d\n", dp[lenA][lenB]);
}
