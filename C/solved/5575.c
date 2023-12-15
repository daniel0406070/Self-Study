#include <stdio.h>

int main(){
    int h1, m1, s1, h2, m2, s2;
    int h, m, s;

    for(int i = 0; i < 3; i++){
        scanf("%d %d %d %d %d %d", &h1, &m1, &s1, &h2, &m2, &s2);
        s = s2 - s1;
        if(s < 0){
            s += 60;
            m2--;
        }
        m = m2 - m1;
        if(m < 0){
            m += 60;
            h2--;
        }
        h = h2 - h1;
        printf("%d %d %d\n", h, m, s);
    }
}