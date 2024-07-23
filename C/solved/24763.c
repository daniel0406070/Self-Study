#include <stdio.h>

int main(){
    int a,b,c,d,e;
    for(int i = 0; i < 2; i++){
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

        printf("%d ", a*6+b*3+c*2+d*1+e*2);
    }
}