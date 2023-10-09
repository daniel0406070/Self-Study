#include <stdio.h> 
#include <stdlib.h>

int cmp(const void *a, const void *b){
    return  *(int *)b - *(int *)a;
}

int main(){
    int n, k, ans = 0;
    scanf("%d %d", &n, &k);
    int a[10];
    for (int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }

    qsort(a, n, sizeof(int), cmp);

    for (int i = 0; i < n; ++i){
        ans += k / a[i];
        k %= a[i];
    }

    printf("%d", ans);
}