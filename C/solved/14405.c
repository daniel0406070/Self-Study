#include <stdio.h>
#include <string.h>

int main(){
    char str[5005];
    scanf("%s", str);

    int len = strlen(str);
    for(int i = 0; i < len; i++){
        if(str[i] == 'p' && str[i+1] == 'i'){
            i++;
        }else if(str[i] == 'k' && str[i+1] == 'a'){
            i++;
        }else if(str[i] == 'c' && str[i+1] == 'h' && str[i+2] == 'u'){
            i += 2;
        }else{
            printf("NO\n");
            return 0;
        }
    }

    printf("YES\n");
}