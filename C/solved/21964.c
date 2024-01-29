#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);

    char a;
    scanf("%c",&a);
    
    for(int i=0;i<n-5;i++){
        scanf("%c",&a);
    }

    for(int i=0;i<5;i++){
        scanf("%c",&a);
        printf("%c",a);
    }
}