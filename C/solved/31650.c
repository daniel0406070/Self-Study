#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
    return  *(int*)b - *(int*)a;
}

int binary_search(int *arr, int n, int target){
    int left = 0;
    int right = n-1;
    int mid;
    while(left <= right){
        mid = (left+right)/2;
        if(arr[mid] > target){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    return left;
}

int main(){
    int time[200005]={0};
    int n,m;
    int tmp;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", &tmp);
        time[i] = tmp;
    }

    for(int i = 0; i < n; i++){
        scanf("%d", &tmp);
        time[i] -= tmp;
    }
    qsort(time, n, sizeof(int), cmp);

    int a,b;
    int cnt = 0;
    for(int i = 0; i < m; i++){
        scanf("%d %d", &a, &b);
        cnt = binary_search(time, n, b);

        if(a<=cnt){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
}