#include <stdio.h>

int main(){
    int num[10]={0,};
    int tmp;
    for(int i = 0; i < 5; i++){
        scanf("%d", &tmp);
        num[tmp]++;
    }

    for(int i = 0; i < 10; i++){
        if(num[i] % 2 == 1){
            printf("%d", i);
            break;
        }
    }
}