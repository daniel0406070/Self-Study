#include <stdio.h>

int main(){
    int ans=0,tmp;

    for(int i = 0; i < 5; i++){
        scanf("%d", &tmp);
        ans += tmp;
    }

    printf("%d", ans);
}