#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    if(n >= 620 && n <= 780){
        printf("Red\n");
    }else if(n >= 590 && n < 620){
        printf("Orange\n");
    }else if(n >= 570 && n < 590){
        printf("Yellow\n");
    }else if(n >= 495 && n < 570){
        printf("Green\n");
    }else if(n >= 450 && n < 495){
        printf("Blue\n");
    }else if(n >= 425 && n < 450){
        printf("Indigo\n");
    }else if(n >= 380 && n < 425){
        printf("Violet\n");
    }
}