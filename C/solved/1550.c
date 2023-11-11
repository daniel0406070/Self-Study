#include <stdio.h>

int main(){
    char a[8];
    scanf("%s", a);

    int result = 0;
    for(int i=0; a[i]!='\0'; i++){
        if(a[i] >= 'A' && a[i] <= 'F'){
            a[i] = a[i] - 'A' + 10;
        }else{
            a[i] = a[i] - '0';
        }
        result = result * 16 + a[i];
    }
    printf("%d", result);
}