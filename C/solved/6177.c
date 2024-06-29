#include <stdio.h>
#include <stdlib.h>

int arr[502]={0,};

int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int main(){
    int n;
    scanf("%d", &n);

    int sum = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    qsort(arr, n, sizeof(int), cmp);

    printf("%lf\n%lf", 1.0*sum/n, n%2==0 ? 1.0*(arr[n/2-1]+arr[n/2])/2 : 1.0*arr[n/2]);

}