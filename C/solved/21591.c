#include <stdio.h>

int main(){
    int a,b,c,d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if(a-2>=c && b-2>=d){
        printf("1");
    }else{
        printf("0");
    }
}