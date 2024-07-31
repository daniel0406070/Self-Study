#include <stdio.h>

int main(){
    int limit;
    int speed;

    scanf("%d", &limit);
    scanf("%d", &speed);

    if(speed <= limit){
        printf("Congratulations, you are within the speed limit!\n");
    } else if(speed <= limit + 20){
        printf("You are speeding and your fine is $100.\n");
    } else if(speed <= limit + 30){
        printf("You are speeding and your fine is $270.\n");
    } else {
        printf("You are speeding and your fine is $500.\n");
    }
}