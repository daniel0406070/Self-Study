#include <stdio.h>
#include <string.h>

int main(){
    char arr[1000002];
    scanf("%s", arr);

    int len = strlen(arr);

    if(len % 3 == 1){
        printf("%d", arr[0]-'0');
    }
    else if(len % 3 == 2){
        printf("%d", (arr[0]-'0')*2+(arr[1]-'0'));
    }

    for(int i=len%3; i<len; i+=3){
        printf("%d", (arr[i]-'0')*4+(arr[i+1]-'0')*2+(arr[i+2]-'0'));
    }


}