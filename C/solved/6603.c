#include <stdio.h>

int n;
int arr[13];
int lotto[6];
int visit[13]={0,};
int back(int k){
    if(k==6){
        for(int i=0;i<6;i++){
            printf("%d ",lotto[i]);
        }
        printf("\n");
    }
    else{
        for(int i=0;i<n;i++){
            if(visit[i]==0&&arr[i]>lotto[k-1]){
                visit[i]=1;
                lotto[k]=arr[i];
                back(k+1);
                visit[i]=0;
                
            }
        }
    }
}

int main(){
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        back(0);
        printf("\n");
    }
}