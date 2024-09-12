#include <stdio.h>

int main(){
    int a,b;
    scanf("%d %d", &a, &b);

    int c = a<b+1 ? a : b+1;
    printf("%d\n", 2*c-1);
}