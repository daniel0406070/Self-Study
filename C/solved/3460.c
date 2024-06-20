#include <stdio.h>

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);

        int count = 0;
        while(n){
            if(n % 2){
                printf("%d ", count);
            }
            n /= 2;
            count++;
        }
        printf("\n");
    }
}