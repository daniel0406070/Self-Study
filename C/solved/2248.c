#include <stdio.h> 

long long int dp[33][33]={0,};

int main(){
    long long int c;
    int a,b;
    scanf("%d %d %lld", &a, &b, &c);

    dp[0][0]=1;
    for(int i=1; i<=a; i++){
        dp[i][0]=dp[i-1][0];
        for(int j=1; j<=b; j++){
        dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
        }
    }


    char ans[33]={0,};

    for(int k=a; k>0; k--){
        long long int sum=0;
        for(int i=0; i<=b; i++){
            sum+=dp[k-1][i];
        }

        // printf("%lld ",sum);
        // for(int i=0; i<=b; i++){
        //     printf("%lld ", dp[k-1][i]);
        // }
        // printf("\n");

        if(sum<c){
            ans[k]='1';
            c-=sum;
            b--;
        }
        else{
            ans[k]='0';
        }
    }
    
    for(int i=a; i>0; i--) printf("%c", ans[i]);
}

