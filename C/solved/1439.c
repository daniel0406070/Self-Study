#include <stdio.h>
#include <string.h>

char a[1000000]={0,};

int main(){
    int zero=0, one=0;
    scanf("%s",a);

    int len=strlen(a);
    for(int i=0; i<len-1; i++){
        if (a[i]!=a[i+1]){
            if (a[i]=='0') zero++;
            else one++;
        }   
    }

    if (a[len-1]=='0') zero++;
    else one++;

    printf("%d\n",zero<one?zero:one);
}