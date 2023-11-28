#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define div 1000000007

typedef long long int lli;

lli doub[20]={0,};

void doub_init(){
    doub[0]=2;
    for(int i=1;i<20;i++) doub[i]=doub[i-1]*doub[i-1]%div;
}

lli get_doub(int n){
    lli sum=1;
    int i=0;

    while(n>0){
        if(n&1==1) sum*=doub[i];
        sum%=div;
        n>>=1;
        i++;
    }

    return sum;
}

int compare(const void *a, const void *b){
    return *(int*)a-*(int*)b;
}


int main(){
    int n;
    scanf("%d",&n);

    doub_init();
    // for(int i=0;i<32;i++) printf("%lld\n",get_doub(i));

    if(n==1){
        printf("0");
        return 0;
    }

    int arr[300002]={0,};
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    qsort(arr,n,sizeof(int),compare);

    lli sum=0;

    for(int i=n-1;i>=0;i--){
        sum += (1LL*arr[i]*get_doub(i))%div;
        sum -= (1LL*arr[i]*get_doub(n-i-1))%div;
        sum%=div;
    }

    printf("%lld",sum<0?sum+div:sum);
}