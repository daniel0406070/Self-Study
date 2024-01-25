#include <stdio.h>

int main(){
    int ans=0,tmp;

    while(1){
        scanf("%d", &tmp);
        if(tmp == -1) break;

        ans+=tmp;
    }
    printf("%d\n", ans);
}