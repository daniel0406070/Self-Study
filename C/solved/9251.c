#include <stdio.h>
#include <string.h>

int main(){
    char A[1002];
    char B[1002];
    scanf("%s", A);
    scanf("%s", B);

    int lenA = strlen(A);
    int lenB = strlen(B);

    int dp[lenA+1][lenB+1];
    for(int i=0; i<=lenA; i++){
        dp[i][0] = 0;
        dp[0][i] = 0;
    }

    for(int i=1; i<=lenA; i++){
        for(int j=1; j<=lenB; j++){
            if(A[i-1] == B[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = dp[i-1][j] > dp[i][j-1]?dp[i-1][j]:dp[i][j-1];
        }
    }
    
    printf("%d\n", dp[lenA][lenB]);
}
