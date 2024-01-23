#include <stdio.h>

int main(){
    int n,k;
    scanf("%d %d",&n,&k);

    int arr[200002]={0,};
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        arr[i+n]=arr[i];
    }

    int sum=0;
    for(int i=0;i<k;i++){
        sum+=arr[i];
    }

    int max=sum;
    for(int i=k;i<2*n;i++){
        sum+=arr[i];
        sum-=arr[i-k];
        if(sum>max) max=sum;
    }

    printf("%d",max);
}