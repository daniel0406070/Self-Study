#include <stdio.h>

int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int i=(c-a)/(a-b);
    c=(c-a)%(a-b)+a;
    while (1){
        i++;   
        c-=a;
        if (c<=0){
            printf("%d",i);
            return 0;
        }
        c+=b;
    }
}