#include <stdio.h>

int main(){
    char buffer[1002];

    int n=0;

    while(1){
        fgets(buffer, 1002, stdin);
        if(buffer[0] == '#') break;

        for(int i=0; buffer[i] != '\0'; i++){
            if(buffer[i] == 'a' || buffer[i] == 'A' ||
               buffer[i] == 'e' || buffer[i] == 'E' ||
               buffer[i] == 'i' || buffer[i] == 'I' ||
               buffer[i] == 'o' || buffer[i] == 'O' ||
               buffer[i] == 'u' || buffer[i] == 'U' ) n++;
        }

        printf("%d\n", n);
        n = 0;
    }
}