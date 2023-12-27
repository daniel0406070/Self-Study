#include <stdio.h>

int main(){
    int n,m;
    scanf("%d %d",&n,&m);

    if((n+m)%2!=0  || n<m){
        printf("-1");
        return 0;
    }
    printf("%d %d",(n+m)/2,(n-m)/2);
}