#include <stdio.h>

int main(){
    int a,b,c,d,e;
    int ans=0;

    scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);

    if(a<0){
        ans+=c*-1*a;
        ans+=d;
        ans+=e*b;
    }
    else{
        ans+=(b-a)*e;
    }

    printf("%d",ans);
}