#include <stdio.h>
#include <stdlib.h>


int main(){
    int n;
    scanf("%d",&n);

    int k;
    scanf("%d",&k);

    long long int high = 1LL*n*n;
    long long int low = 1;
    long long int mid,cnt;

    while(1){
        mid = (high+low)/2;
        cnt = 0;
        
        for(int i=1;i<=n;i++){
            cnt += (mid/i>n)?n:mid/i;
        }

        if(cnt<k){
            low = mid+1;
        }
        else{
            high = mid-1;
        }

        

        if(low>high){
            printf("%lld",low);
            break;
        }
    }
}