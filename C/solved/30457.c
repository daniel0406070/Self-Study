#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int main(){
    int n;
    scanf("%d", &n);

    int h[1002]={0,};
    for(int i=0; i<n; i++){
        scanf("%d", &h[i]);
    }
    qsort(h, n, sizeof(int), cmp);

    int count=1;
    int h_left[1002]={0,};
    int left=0;
    for(int i=1; i<n; i++){
        if(h[i-1]<h[i]) {
            count++;
        }
        else{
            h_left[left++]=h[i];
        }
    }

    qsort(h_left, left, sizeof(int), cmp);
    if(left!=0)count++;
    for(int i=1; i<left; i++){
        if(h_left[i-1]<h_left[i]) {
            count++;
        }
    }

    printf("%d", count);
    

}