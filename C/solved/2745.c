#include <stdio.h>

int main(){
    char str[100];
    int b;

    scanf("%s %d", str, &b);

    int ans = 0;

    for(int i=0; str[i]; i++){
        ans *= b;
        if(str[i] >= '0' && str[i] <= '9')
            ans += str[i] - '0';
        else
            ans += str[i] - 'A' + 10;
    }

    printf("%d\n", ans);
}