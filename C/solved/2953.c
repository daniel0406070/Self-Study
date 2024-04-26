#include <stdio.h>

int main(){
    int arr[5]={0,};

    for(int i=0; i<5; i++){
        for(int j=0; j<4; j++){
            int a;
            scanf("%d", &a);
            arr[i]+=a;
        }
    }

    int max=0, idx=0;
    for(int i=0; i<5; i++){
        if(arr[i]>max){
            max=arr[i];
            idx=i;
        }
    }

    printf("%d %d", idx+1, max);
}