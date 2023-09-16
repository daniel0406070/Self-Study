#include <stdio.h>

int main(){
    int num;
    printf("정수를 입력하세요: ");
    scanf("%d", &num);
    
    printf("연산의 결과는 %u입니다\n", num^63);
}