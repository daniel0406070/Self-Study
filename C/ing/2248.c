#include <stdio.h> 

int dp[33][33]={0,};

int main(){
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);

    dp[1][1]=1;

    for(int j=2; j<=a; j++){
        dp[1][j]=dp[1][j-1]+1;
        for(int i=2; i<=j; i++){
            dp[i][j]=dp[i-1][j-1]+1;
            dp[i][j]+=dp[i-1][j];
        }
    }

    for(int i=1; i<=a; i++){
        for(int j=1; j<=a; j++){
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }

    char ans[33]={0,};

    for(int k=b; k>0; k--){
            if(dp[k][i]>c){
                ans[i]='1';
                c-=dp[k][i]; m
                break;
            }
            else if(dp[k][i]==c){
                for(int j=i; j>0; j--){
                    ans[j]='1';
                }
                c=0;
                break;
            }
        }
    }
    
    for(int i=a; i>0; i--){
        if(ans[i]=='1') printf("1");
        else printf("0");
    }
}

