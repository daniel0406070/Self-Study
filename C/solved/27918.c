#include <stdio.h>

int main(){
    int n;

    char c;
    int a=0,b=0;

    scanf("%d",&n);

    for (int i = 0; i < n; i++){
        while(getchar()!='\n');
        scanf("%c",&c);
        

        if(c=='D') a++;
        else b++;

        if(a-b>1 || a-b<-1) break;
    }
    
    printf("%d:%d",a,b);
}