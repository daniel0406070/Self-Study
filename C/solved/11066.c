#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main(){
    int t;
    scanf("%d",&t);
    int n;

    while(t--){
        scanf("%d",&n);
        int *arr=malloc(sizeof(int)*n);
        int *sum=malloc(sizeof(int)*n);
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
            if(i==0) sum[i]=arr[i];
            else sum[i]=sum[i-1]+arr[i];
        }
        int **dp=malloc(sizeof(int*)*n);

        for(int i=0;i<n;i++){
            dp[i]=malloc(sizeof(int)*n);
            for(int j=0;j<n;j++){
                dp[i][j]=0;
            }
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<n-i;j++){
                int s=j;
                int e=i+j;

                int min=0x7fffffff;
                for(int k=s;k<e;k++){
                    if(min>dp[s][k]+dp[k+1][e]+sum[e]-sum[s-1]){
                        min=dp[s][k]+dp[k+1][e]+sum[e]-sum[s-1];
                    }
                }
                dp[s][e]=min;
            }
        }

        printf("%d\n",dp[0][n-1]);
        for(int i=0;i<n;i++){
            free(dp[i]);
        }
        free(dp);
        free(arr);
    }
}