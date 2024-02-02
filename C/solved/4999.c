#include <stdio.h>

int main(){
    int a=0, b=0;
    char c[1000];
    
    scanf("%s", c);
    for(int i=0;c[i]!='\0';i++){
        a++;
    }

    scanf("%s", c);
    for(int i=0;c[i]!='\0';i++){
        b++;
    }

    if (a>=b){
        printf("go");
    } else {
        printf("no");
    }
}