#include <stdio.h>

int main(){
    int b=0, a=0, tmp;
    for(int i=0; i<10; i++){
        scanf("%d", &tmp);
        b = a;
        a += tmp;
        if(a >= 100){
            break;
        }
    }

    if(100 - b < a - 100){
        printf("%d\n", b);
    }else{
        printf("%d\n", a);
    }
}