#include <stdio.h>
#include <stdlib.h>

int arr[2000003];

int cmp(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int main(){
    int n;
    scanf("%d", &n);

    int tmp;
    for(int i = 0; i < n; i++){
        scanf("%d", &tmp);
        arr[tmp+1000000]++;
    }

    for(int i = 2000001; i >= 0; i--){
        if(arr[i] > 0){
            printf("%d\n", i-1000000);
        }
    }
}