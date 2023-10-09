#include <stdio.h>
#include <stdlib.h>

int people[1000];

int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int main(){
    int n;
    scanf("%d",&n);

    for(int i=0; i<n; i++){
        scanf("%d",&people[i]);
    }
    qsort(people, n, sizeof(int), cmp);

    int sum = 0;
    for(int i=0; i<n; i++){
        sum += people[i] * (n-i);
    }

    printf("%d\n",sum);
}   