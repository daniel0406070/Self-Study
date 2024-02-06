#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char a[101][101];
    int n;

    scanf("%s",a[0]);
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        scanf("%s",a[i]);
    }

    int cnt=0;  
    for(int i=1;i<=n;i++){
        if(strcmp(a[0],a[i])==0){
            cnt++;
        }
    }

    printf("%d",cnt);
}