#include <stdio.h>

int main(){
    int a1,a2,b1,b2;
    scanf("%d %d", &a1, &a2);
    scanf("%d %d", &b1, &b2);

    if(a1*b2 > b1*b1*a2*3.14159265358979323846){
        printf("Slice of pizza");
    }else{
        printf("Whole pizza");
    }
}