#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    char s[1001];
    scanf("%s", s);

    int len = strlen(s);
    char **arr = (char**)malloc(sizeof(char*)*len);
    for(int i=0; i<len; i++){
        arr[i] = s+i;
    }

    for(int i=0; i<len; i++){
        for(int j=i+1; j<len; j++){
            if(strcmp(arr[i], arr[j])>0){
                char* temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for(int i=0; i<len; i++){
        printf("%s\n", arr[i]);
    }

}