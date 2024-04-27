#include <stdio.h>

int dp[300][300]={0,};
int ddp[300][300]={0,};

int main(){
    int n,m;
    scanf("%d %d",&n,&m);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d",&dp[i][j]);
            ddp[i][j]=dp[i][j];

            dp[i][j]+=i>0?dp[i-1][j]:0;
            ddp[i][j]+=j>0?ddp[i][j-1]:0;
        }
    }

    int k;
    int x1,y1,x2,y2;
    scanf("%d",&k);
    for(int i=0; i<k; i++){
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        x1--; y1--; x2--; y2--;
        int sum=0;
        if(x2-x1>y2-y1){
            for(int j=y1; j<=y2; j++){
                sum+=dp[x2][j]-(x1>0?dp[x1-1][j]:0);
            }
        }
        else{
            for(int j=x1; j<=x2; j++){
                sum+=ddp[j][y2]-(y1>0?ddp[j][y1-1]:0);
            }
        }
        printf("%d\n",sum);
    }
}