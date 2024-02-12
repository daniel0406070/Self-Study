#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int a[60], b[60];

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), cmp);
    for(int i = 0; i < n; i++) scanf("%d", &b[i]);
    qsort(b, n, sizeof(int), cmp);

    long long int sum = 0;
    for(int i = 0; i < n; i++) sum += a[i] * b[n - i - 1];

    printf("%lld\n", sum);
}