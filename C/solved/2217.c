#include <stdio.h>
#include <stdlib.h>

rope[100002];

int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int main(){
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &rope[i]);
    }

    qsort(rope, n, sizeof(int), cmp);

    int max = 0;
    for(int i=0; i<n; i++){
        if(rope[i] * (n-i) > max){
            max = rope[i] * (n-i);
        }
    }

    printf("%d\n", max);
}