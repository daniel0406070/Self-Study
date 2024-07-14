#include <stdio.h>

int main(){
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);

    if(b==c) printf("Anything\n");
    else if(b<c) printf("Bus\n");
    else printf("Subway\n");
}