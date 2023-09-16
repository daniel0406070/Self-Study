#include <stdio.h>

int main(){
    double num;
    printf("반올림할 소수를 입력하세요: ");
    scanf("%lf", &num);
    printf("%s\n", (int)(num*10)%10>=5?"반올림하면 일의 자리 숫자가 커집니다":"반올림해도 일의 자리 숫자는 그대로 입니다");
}   