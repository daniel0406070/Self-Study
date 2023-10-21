#include <stdio.h>

int main(){
    int e,s,m;
    scanf("%d %d %d",&e,&s,&m);
    int i=1;
    while(1){
        if((i-e)%15==0&&(i-s)%28==0&&(i-m)%19==0){
            printf("%d",i);
            break;
        }
        i++;
    }
}