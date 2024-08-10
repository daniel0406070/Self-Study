#include <stdio.h>

int main(){
    int n;
    for(int i=0; i<8; i++){
        scanf("%d", &n);
        if(n==9) {
            printf("F");
            return 0;
        }
    }
    printf("S");
}