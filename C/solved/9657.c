#include <stdio.h>

int dp[1002]={0,};

int main(){
    int n;
    scanf("%d", &n);

    dp[1]=1;
    dp[2]=0;
    dp[3]=1;
    dp[4]=1;
    for(int i=4; i<=n; i++){
        if(dp[i-1]==0 || dp[i-3]==0 || dp[i-4]==0){
            dp[i]=1;
        }
        else{
            dp[i]=0;
        }
    }

    if(dp[n]==1){
        printf("SK\n");
    }
    else{
        printf("CY\n");
    }
}
