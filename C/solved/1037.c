#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int main(){
    int n;
    scanf("%d", &n);

    int a[51];
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp);

    int ans;
    if(n%2 == 0) ans = a[0] * a[n-1];
    else ans = a[n/2] * a[n/2];
    
    printf("%d", ans);
}