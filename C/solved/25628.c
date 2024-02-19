#include <stdio.h>

int main(){
    int n,m;
    scanf("%d %d", &n, &m);

    printf("%d", n/2>m?m:n/2);
}