#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n, c;
    char s[100];

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", s);
        c = strlen(s);
        printf("%s\n", (c>5&&c<10)?"yes":"no");
    }
}