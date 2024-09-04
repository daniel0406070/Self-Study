#include <stdio.h>

int main(){
    int n, a, b, c, d;
    scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);

    int aa = ((n-1)/a+1)*b;
    int bb = ((n-1)/c+1)*d;

    printf("%d", aa < bb ? aa : bb);
}