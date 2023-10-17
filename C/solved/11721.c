#include <stdio.h>

int main(){
    char a[102];
    scanf("%s",a);

    for(int i=0; a[i]!='\0'; i++){
        printf("%c",a[i]);
        if (i%10==9){
            printf("\n");
        }
    }
}