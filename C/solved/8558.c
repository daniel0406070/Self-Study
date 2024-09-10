#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int a=1;
    for(int i=1; i<=n; i++){
        a*=i;
        a%=10;
    }

    printf("%d", a);
}