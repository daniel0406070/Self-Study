#include <stdio.h>

int main(){
    int n,m;
    int ans=0,max=0;

    for (int i = 0; i < 4; i++)
    {
        scanf("%d %d",&n,&m);
        ans+=m-n;

        if(max<ans) max=ans;
    }
    printf("%d",max);
}