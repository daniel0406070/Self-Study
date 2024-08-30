#include <stdio.h>

int main() {
    int n,m;
    scanf("%d %d", &n, &m);

    int a = 100 - n;
    int b = 100 - m;
    int c = 100 - a - b;
    int d = a*b;
    int q = d/100;
    int r = d%100;

    printf("%d %d %d %d %d %d\n", a, b, c, d, q, r);
    printf("%d %d\n", c+q, r);
}