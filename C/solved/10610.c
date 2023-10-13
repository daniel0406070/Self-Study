#include <stdio.h>

int num[10];

int main(){
    char tmp;
    int sum = 0;
    while(1){
        scanf("%c", &tmp);
        if (tmp == '\n') break;
        num[tmp-'0']++;
        sum += tmp-'0';
    }

    if(num[0] == 0 || sum % 3 != 0){
        printf("-1");
        return 0;
    }

    for(int i = 9; i >= 0; i--){
        for(int j = 0; j < num[i]; j++){
            printf("%d", i);
        }
    }
}