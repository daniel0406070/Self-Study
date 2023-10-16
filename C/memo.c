#include <stdio.h>

int a[10]={1,5,7,8,9,125,741,1256,6432,12311};

int bi(int p){
    int left=0;
    int right=9;
    int mid;
    int idx=0;


    while(left<=right){
        mid=(left+right)/2;
        if (a[mid]>p){
            right=mid-1;
        }
        else if (a[mid+1]<=p){
            left=mid+1;
        }
        else{
            idx=mid;
            break;  
        }
    }
    if (idx!=mid){
        idx=left;
    }
    return idx;
}

int main(){
    for(int i=0; i<12311; i++){
        int c=bi(i);
        if (a[c]<=i && a[c+1]>i){
            continue;
        }
        else{
            printf("%d ,%d\n",i,c);
        }
    }
}