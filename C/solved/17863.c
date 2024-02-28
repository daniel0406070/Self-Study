#include <stdio.h>

int main(){
    char a;

    for(int i = 0; i < 3; i++){
        scanf("%c", &a);
        if(a != '5'){
            printf("NO\n");
            return 0;
        }
    }

    printf("YES\n");
}