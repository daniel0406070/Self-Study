#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    char str[102];
    char c;

    for(int i = 0; i < n; i++){
        c = -1;
        scanf("%s", str);
    
        for(int j = 0; str[j] != '\0'; j++){
            if(c!=str[j])
                printf("%c", str[j]);
            c = str[j];
        }
        printf("\n");
    }
}