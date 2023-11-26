#include <stdio.h>

int main(){
    int num[7], sum = 0, min = 100;
    for(int i = 0; i < 7; i++){
        scanf("%d", &num[i]);
        if(num[i] % 2 == 1){
            sum += num[i];
            if(min > num[i]) min = num[i];
        }
    }

    if(sum == 0) printf("-1");
    else printf("%d\n%d", sum, min);
}