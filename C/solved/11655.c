#include <stdio.h>

int main(){
    char str[101];
    fgets(str, 101, stdin);

    for(int i=0; str[i]!='\0'; i++){
        if(str[i]>='a' && str[i]<='z') str[i]=(str[i]-'a'+13)%('z'-'a'+1)+'a';
        else if(str[i]>='A' && str[i]<='Z') str[i]=(str[i]-'A'+13)%('Z'-'A'+1)+'A';
    }

    printf("%s", str);
}