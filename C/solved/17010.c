#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int a;
    char b;
    for(int i=0; i<n; i++){
        scanf("%d %c", &a, &b);
        for(int j=0; j<a; j++){
            printf("%c", b);
        }
        printf("\n");
    }
}