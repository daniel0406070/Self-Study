#include <stdio.h>

int main(){
    char str[340000];
    scanf("%s", str);

    for(int i=0; str[i]; i++){
        if(i==0){
            if(str[i]=='0') printf("0");
            else if(str[i]=='1') printf("1");
            else if(str[i]=='2') printf("10");
            else if(str[i]=='3') printf("11");
            else if(str[i]=='4') printf("100");
            else if(str[i]=='5') printf("101");
            else if(str[i]=='6') printf("110");
            else if(str[i]=='7') printf("111");
        }
        else{
            if(str[i]=='0') printf("000");
            else if(str[i]=='1') printf("001");
            else if(str[i]=='2') printf("010");
            else if(str[i]=='3') printf("011");
            else if(str[i]=='4') printf("100");
            else if(str[i]=='5') printf("101");
            else if(str[i]=='6') printf("110");
            else if(str[i]=='7') printf("111");
        }
    }
}