#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int move[100002][3]={0,};

int cmp(const void *a, const void *b){
    int *pa=(int*)a;
    int *pb=(int*)b;

    if(pa[2]>pb[2]){
        return -1;
    }
    else if(pa[2]<pb[2]){
        return 1;
    }
    else{
        if(pa[0]>pb[0]){
            return -1;
        }
        else if(pa[0]<pb[0]){
            return 1;
        }
        else{
            return 0;
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);

    int a,b;
    for(int i=0; i<n; i++){
        scanf("%d %d", &a, &b);
        move[i][0]=a;
        move[i][1]=b;
        move[i][2]=a-b;
    }

    qsort(move, n, sizeof(int)*3, cmp);

    long long int h=0;
    long long int min_h=0;
    long long int ans=0;
    for(int i=0; i<n; i++){
        ans+=h+move[i][0];
        h+=move[i][2];
        if(h<min_h){
            min_h=h;
        }
    }
    ans+=-min_h*n;
    
    printf("%lld", ans);
} 