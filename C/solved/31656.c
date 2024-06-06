#include <stdio.h>

int main(){
    char str[1004];
    fgets(str, 1004, stdin);

    printf("%c", str[0]);
    for(int i = 1; str[i] != '\0'; i++){
        if(str[i] != str[i-1]){
            printf("%c", str[i]);
        }
    }
}