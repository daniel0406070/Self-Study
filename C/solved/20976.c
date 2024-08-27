#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int main(){
    int a[3];
    scanf("%d %d %d", a, a+1, a+2);
    qsort(a, 3, sizeof(int), cmp);
    printf("%d", a[1]);
}