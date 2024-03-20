#include <stdio.h>

int main(){
    int a,b,c;

    int i=1;
    while(1){
        scanf("%d %d %d", &a, &b, &c);
        if(a == 0 && b == 0 && c == 0) break;

        printf("Case %d: %d\n", i++, (c/b)*a+(c%b > a ? a : c%b));
    }
}