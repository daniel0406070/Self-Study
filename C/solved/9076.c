#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int main(){
    int n;
    scanf("%d", &n);

    int arr[5];
    for(int i=0; i<n; i++){
        for(int j=0; j<5; j++){
            scanf("%d", &arr[j]);
        }

        qsort(arr, 5, sizeof(int), cmp);

        if(arr[3]-arr[1] >= 4){
            printf("KIN\n");
        }else{
            int sum=0;
            for(int j=1; j<4; j++){
                sum+=arr[j];
            }

            printf("%d\n", sum);
        }
    }
}