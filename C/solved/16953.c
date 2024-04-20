#include <stdio.h>


int main(){
    int n,m;
    scanf("%d %d",&n,&m);

    int cnt=0;
    while(1){
        if(n==m){
            printf("%d\n",cnt+1);
            break;
        }
        else if(n>m){
            printf("-1\n");
            break;
        }
        else if(m%10==1){
            m/=10;
            cnt++;
        }
        else if(m%2==0){
            m/=2;
            cnt++;
        }
        else{
            printf("-1\n");
            break;
        }
    }
}
     