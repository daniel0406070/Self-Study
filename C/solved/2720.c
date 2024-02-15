#include <stdio.h>

int main(){
    int t,n;
    int a,b,c,d;

    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        scanf("%d", &n);
        a = n / 25;
        n = n % 25;
        b = n / 10;
        n = n % 10;
        c = n / 5;
        n = n % 5;
        d = n / 1;
        printf("%d %d %d %d\n", a, b, c, d);
    }
}