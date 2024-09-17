#include <stdio.h>

int main(){
    int h1, m1, s1, h2, m2, s2;
    scanf("%d : %d : %d", &h1, &m1, &s1);
    scanf("%d : %d : %d", &h2, &m2, &s2);

    int t1 = h1 * 3600 + m1 * 60 + s1;
    int t2 = h2 * 3600 + m2 * 60 + s2;

    if(t1 > t2) t2 += 24 * 3600;

    int t = t2 - t1;
    printf("%d", t);
}