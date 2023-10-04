#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}


int num[10002]={0,};
int main(){
    int n,tmp;
    scanf("%d", &n);
    for (int i=0;i<n;i++){
        scanf("%d", &tmp);
        num[tmp]++;
    }
    for (int i=1;i<10001;i++){
        for (int j=0;j<num[i];j++){
            printf("%d\n", i);
        }
    }
}