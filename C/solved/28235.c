#include <stdio.h>

int main(){
    char str[100];
    scanf("%s", str);

    if(str[0]=='S')
        printf("HIGHSCHOOL");
    else if (str[0]=='C')
        printf("MASTER");
    else if (str[0]=='2')
        printf("0611");
    else
        printf("CONTEST");
}