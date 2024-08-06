#include <stdio.h>

int main(){
    int n,m;
    scanf("%d %d", &n, &m);

    n/=2;
    m/=2;

    printf("%d", m>n ? n : m);
}