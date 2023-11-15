#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int binarySearch(int *arr, double target, int n){
    int left = 0;
    int right = n-1;
    int mid = (left+right)/2;
    while(left<=right){
        if(arr[mid]==target) return mid;
        else if(arr[mid]<target && (mid==n-1 || arr[mid+1]>target)) return mid;
        else if(arr[mid]>target) right=mid-1;
        else left=mid+1;
        mid=(left+right)/2;
    }
    return -1;
}



int main(){
    int n,m,r;
    scanf("%d %d %d", &n, &m, &r);
    r=r*2;

    int A[2002];
    int B[40002];
    int len[40003]={0,};

    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
        for(int j = 0; j < i; j++){
            if(A[i]>A[j]) len[A[i]-A[j]]=1;
            else len[A[j]-A[i]]=1;
        }
    }
    for(int i = 0; i < m; i++){
        scanf("%d", &B[i]);
    }
    qsort(B, m, sizeof(int), cmp);

    double max = -1;
    double area = 0;
    for(int i = 1; i < 40001; i++){
        if(len[i]==0) continue;

        area=r/i;
        if(area>0){
            int idx = binarySearch(B, area, m);
            if(idx==-1) continue;
            if(area<B[idx]) continue;
            if(max<B[idx]*i) max=B[idx]*i;
        }
    }

    if(max==-1) printf("-1");
    else printf("%.1lf", max/2);


}