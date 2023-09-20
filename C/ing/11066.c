#include <stdio.h>
#include <stdlib.h>

int dp[502];


int main() {
    int t;
    scanf("%d",&t);
    while (t--){
        int n,tmp;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d",&tmp);
            dp[i]=tmp;   
        }
        printf("%d\n",count);
    }
}