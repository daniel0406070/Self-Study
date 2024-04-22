#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);

    int count = 0;
    while(n > 0){
        if(n % 5 == 0){
            printf("%d\n", count + n / 5);
            return 0;
        }
        n -= 2;
        count++;
    }

    if(n == 0){
        printf("%d\n", count);
    }
    else{
        printf("-1\n");
    }

}