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
            if(A[i-1] == B[j-1]) { // 같다면 대각선 위의 값 + 1
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                if( dp[i-1][j] > dp[i][j-1]){ // 다르다면 왼쪽이나 위에서 값을 가져왔으므로 둘 중 큰 값을 선택하면 된다.
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
    }

    char result[1002];

    int i = lenA;
    int j = lenB;
    int k = dp[lenA][lenB];

    
    while(i > 0 && j > 0){
        if(A[i-1] == B[j-1]){
            result[k-1] = A[i-1];
            i--;
            j--;
            k--;
        }
        else{
            if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }

    result[dp[lenA][lenB]] = '\0';


    
    printf("%d\n", dp[lenA][lenB]);
    printf("%s\n", result);
}
