#include <stdio.h>

int main(){
    int won;
    printf("금액을 입력하세요: ");
    scanf("%d", &won);

    printf("오만원권 %d장\n", won/50000);
    won %= 50000;
    printf("만원권 %d장\n", won/10000);
    won %= 10000;
    printf("천원권 %d장\n", won/1000);
    won %= 1000;
    printf("백원짜리 %d개\n", won/100);
    won %= 100;
    printf("십원짜리 %d개\n", won/10);
    won %= 10;

}