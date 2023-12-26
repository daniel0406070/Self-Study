#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    getchar();

    char s[52];
    for(int i=1; i<=n; i++){
        fgets(s, 52, stdin);
        printf("%d. %s", i, s);
    }
}