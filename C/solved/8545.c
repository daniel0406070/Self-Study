#include <stdio.h>

int main(){
    char c[5];
    scanf("%s", c);

    for(int i = 2; i >=0 ; i--){
        printf("%c", c[i]);
    }
}