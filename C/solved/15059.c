#include <stdio.h>

int main(){
    int a1,b1,c1,a2,b2,c2;
    scanf("%d %d %d", &a1, &b1, &c1);
    scanf("%d %d %d", &a2, &b2, &c2);

    printf("%d", (a1<a2?a2-a1:0) + (b1<b2?b2-b1:0) + (c1<c2?c2-c1:0));
}