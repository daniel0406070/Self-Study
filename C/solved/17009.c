#include <stdio.h>

int main(){
    int a=0, b=0;
    int tmp;

    for(int i=0;i<3;i++){
        scanf("%d", &tmp);
        a+=(3-i)*tmp;
    }
    for(int i=0;i<3;i++){
        scanf("%d", &tmp);
        b+=(3-i)*tmp;
    }

    if (a>b){
        printf("A");
    } else if (a<b){
        printf("B");
    } else {
        printf("T");
    }
}