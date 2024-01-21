#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);

    int x,y;
    for(int i=0;i<n;i++){
        scanf("%d %d",&x,&y);
        printf("%s\n",x>=y?"MMM BRAINS":"NO BRAINS");
    }
}