#include <stdio.h>
#include <string.h>

int main(){
    char str[350];
    fgets(str, 350, stdin);

    int len=strlen(str)/3;
    for(int i=0; i<len; i++){
        if(str[i]==str[i+len])
            printf("%c", str[i]);
        else if(str[i]==str[i+len*2])
            printf("%c", str[i]);
        else
            printf("%c", str[i+len]);
    }
    
}