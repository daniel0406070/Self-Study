#include <stdio.h>

int main(){
    char str[40];
    scanf("%s", str);

    int cnt = 0;
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == ':') cnt++;
        else if(str[i] == '_') cnt+=5;
        cnt++;
    }

    printf("%d", cnt);
}