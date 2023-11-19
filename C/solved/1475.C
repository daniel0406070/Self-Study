#include <stdio.h>

int main(){
    char num[8];
    int count[10] = {0,};
    int max = 0;

    scanf("%s", num);
    for(int i = 0; num[i] != '\0'; i++){
        if(num[i] == '9' || num[i] == '6'){
            if(count[6] > count[9]){
                count[9]++;
            }else{
                count[6]++;
            }
        }else{
            count[num[i] - '0']++;
        }
    }

    for(int i = 0; i < 10; i++){
        if(count[i] > max){
            max = count[i];
        }
    }

    printf("%d", max);

}