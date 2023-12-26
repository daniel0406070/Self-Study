#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
    return *(int*)b - *(int*)a;
}

int main(){
    int n,m;
    scanf("%d %d", &n, &m);

    int arr[1002];
    for(int i=0; i<n; i++) 
        scanf("%d", &arr[i]);
    qsort(arr, n, sizeof(int), cmp);

    printf("%d\n", arr[m-1]);
    
}