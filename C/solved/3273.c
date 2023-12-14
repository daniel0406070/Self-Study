#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int main(){
    int n,m;
    int num[100000]={0,};

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    scanf("%d",&m);
    qsort(num,n,sizeof(int),cmp);

    int count=0;
    int left=0,right=n-1;

    while(left<right){
        if(num[left]+num[right]==m){
            count++;
            left++;
            right--;
        }
        else if(num[left]+num[right]<m){
            left++;
        }
        else{
            right--;
        }
    }

    printf("%d",count);
}