#include <stdio.h>

int main(){
    int num;
    printf("정수를 입력하세요: ");
    scanf("%d", &num);
    int rvs = 0;
    if(num){
        rvs *= 10;
        rvs += num % 10;
        num /= 10;
    } 
    if(num){
        rvs *= 10;
        rvs += num % 10;
        num /= 10;
    } 
    if(num){
        rvs *= 10;
        rvs += num % 10;
        num /= 10;
    } 
    if(num){
        rvs *= 10;
        rvs += num % 10;
        num /= 10;
    } 
    if(num){
        rvs *= 10;
        rvs += num % 10;
        num /= 10;
    } 
    if(num){
        rvs *= 10;
        rvs += num % 10;
        num /= 10;
    } 
    

    printf("해당 정수를 뒤집으면 %d\n", rvs);
}