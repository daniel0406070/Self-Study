#include <stdio.h>

int main(){
    int h, m, d;
    scanf("%d %d %d", &d, &h, &m);

    h += d*24;
    m += h*60;
    m -= 16511;

    if(m < 0){
        printf("-1");
    }else{
        printf("%d", m);
    }

    
}