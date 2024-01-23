#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);

    int m,tmp;
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d",&tmp);
        n-=tmp;
    }
    
    printf("%s",n<=0?"Padaeng_i Happy":"Padaeng_i Cry");
}