#include <stdio.h>

int main(){
    int n;
    int tmp, cnt=0, ac=1;

    scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d",&tmp);

        if(tmp==1){
            cnt += ac;
            ac++;
        }
        else ac=1;
    }
    
    printf("%d", cnt);
}