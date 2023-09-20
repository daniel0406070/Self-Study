#include <stdio.h>
#include <stdlib.h>

int tree[102];

long long int cut(int n,int m){
    long long int sum=0;
    for(int i=0;i<n;i++){
        if(tree[i]>m){
            sum+=tree[i]-m;
        }
    }
    return sum;
}

int binary(int n,int m){
    int left=0;
    int right=1000000000;
    int mid;
    int result=0;
    while(left<=right){
        mid=(left+right)/2;
        if(cut(n,mid)>=m){
            result=mid;
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return result;
}

int main(){
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d",&tree[i]);
        }

        printf("%d\n",binary(n,m));
    }

}