#include <stdio.h>

int main(){
    int n,m;
    scanf("%d", &n);
    scanf("%d", &m);

    int tmp, min=m;

    if(n>=20){
        tmp=(m*3)/4;
        if(tmp<min){
            min=tmp;
        }
    }
    if (n>=15){
        tmp=m-2000;
        if(tmp<min){
            min=tmp;
        }
    }
    if(n>=10){
        tmp=(m*9)/10;
        if(tmp<min){
            min=tmp;
        }
    }
    if(n>=5){
        tmp=m-500;
        if(tmp<min){
            min=tmp;
        }
    }

    printf("%d", min>0?min:0);
}