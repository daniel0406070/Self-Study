#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int main(){
    int arr[5];
    for(int i = 0; i < 5; i++){
        scanf("%d", &arr[i]);
    }
    qsort(arr, 5, sizeof(int), cmp);

    printf("%d\n%d\n", (arr[0] + arr[1] + arr[2] + arr[3] + arr[4]) / 5, arr[2]);

}