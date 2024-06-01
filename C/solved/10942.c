#include <stdio.h>
#include <stdlib.h>

int dp[2001][2001]={0,};

int main(){
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(sizeof(int)*(n+1));
    for(int i=1; i<=n; i++){
        scanf("%d", &arr[i]);
    }
    for(int i=1; i<=n; i++){
        dp[i][i]=1;
    }
    for(int i=1; i<n; i++){
        if(arr[i]==arr[i+1]){
            dp[i][i+1]=1;
        }
    }
    for(int i=2; i<n; i++){
        for(int j=1; j<=n-i; j++){
            if(arr[j]==arr[j+i] && dp[j+1][j+i-1]==1){
                dp[j][j+i]=1;
            }
        }
    }
    int m;
    scanf("%d", &m);
    for(int i=0; i<m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", dp[a][b]);
    }
}