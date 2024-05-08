#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int main(){
    int arr[8], sum = 0;
    int tarr[8];

    for(int i = 0; i < 8; i++){
        scanf("%d", &arr[i]);
        tarr[i] = arr[i];
    }


    
    qsort(tarr, 8, sizeof(int), cmp);
    int flag = tarr[3];

    for(int i = 3; i < 8; i++){
        sum += tarr[i];
    }
    printf("%d\n", sum);
    
    for(int i = 0; i < 8; i++){
        if(arr[i] >= flag){
            printf("%d ", i+1);
        }
    }

}