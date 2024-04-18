#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int main(){
    int *arr;
    int n;
    int k;
    
    scanf("%d", &n);
    scanf("%d", &k);
    arr = (int *)malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), cmp);

    printf("%d\n", arr[k - 1]);
}
