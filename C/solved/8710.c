#include <stdio.h>

int main(){
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);

    b-=a;
    if(b<=0){
        printf("0\n");
        return 0;
    }
    printf("%d\n", (b-1)/c+1);
}