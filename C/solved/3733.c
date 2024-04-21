#include <stdio.h>

int main(){
    int n,m;
    while(
    scanf("%d %d",&n,&m)!=EOF){
        n++;
        printf("%d\n",m/n);
    }
}