#include <stdio.h>

int main(){
    int n,tmp,cnt=0;

    scanf("%d", &n);

    for(int i=0;i<5;i++){
        scanf("%d", &tmp);
        if (tmp==n) cnt++;
    }

    printf("%d", cnt);
}