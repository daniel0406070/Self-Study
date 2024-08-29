#include <stdio.h>

int main(){
    char str[400];
    while(fgets(str, 400, stdin) != NULL)
        printf("%s", str);
}