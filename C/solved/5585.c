#include <stdio.h>

int main(){
    int n;
    int count = 0;
    scanf("%d",&n);
    n = 1000 - n;

    while(n > 0){
        if(n >= 500){
            n -= 500;
            count++;
        }
        else if(n >= 100){
            n -= 100;
            count++;
        }
        else if(n >= 50){
            n -= 50;
            count++;
        }
        else if(n >= 10){
            n -= 10;
            count++;
        }
        else if(n >= 5){
            n -= 5;
            count++;
        }
        else{
            n -= 1;
            count++;
        }
    }

    printf("%d",count);

}