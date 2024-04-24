#include <stdio.h>

int arr[2000]={0,};
int front=0, rear=0;


int main(){
    int n;
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        arr[rear++]=i;
    }

    while(front!=rear){
        printf("%d ", arr[front++]);
        arr[rear++]=arr[front++];
    }

}