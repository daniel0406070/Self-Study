#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    n=(n-1)%8+1;
    
    if(n>5)
        printf("%d",10-n);
    else
        printf("%d",n);
}