#include <stdio.h>

int main(){
    char a;
    printf("알파벳 소문자를 입력하세요: ");   
    scanf("%c", &a);

    a=(a-'a'+3)%('z'-'a'+1)+'a';
    printf("3글자 뒤의 알파벳은 %c\n", a);

}