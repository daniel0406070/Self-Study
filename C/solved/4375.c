#include <stdio.h>

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        int num = 0;
        int cnt = 0;
        while(1){
            num = num * 10 + 1;
            num %= n;
            cnt++;
            if(num == 0){
                printf("%d\n", cnt);
                break;
            }
        }
    }
}