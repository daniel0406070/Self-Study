#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n,s;
    scanf("%d %d",&n,&s);

    short *arr = (short*)malloc(sizeof(short)*n);
    for(int i=0;i<n;i++){
        scanf("%hd",&arr[i]);
    }

    int sum = 0;
    int left = 0;
    int right = 0;
    int min = 100001;

    while(1){
        if(sum<s){
            if(right==n){
                break;
            }
            sum += arr[right++];
        }else{
            if(min>right-left){
                min = right-left;
            }
            sum -= arr[left++];
        }
    }

    printf("%d",min==100001?0:min);

}