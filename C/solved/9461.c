#include <stdio.h>

long long int dp[101]={0,};

long long int wave(int n){
    if(dp[n] != 0) return dp[n];
    
    dp[n]=wave(n-1)+wave(n-5);
    return dp[n];
}

int main(){
    int t;
    scanf("%d", &t);

    dp[1]=1;
    dp[2]=1;
    dp[3]=1;
    dp[4]=2;
    dp[5]=2;

    for (int i = 0; i < t; i++){
        int n;
        scanf("%d",&n);

        printf("%lld\n",wave(n));
    }

    

}
