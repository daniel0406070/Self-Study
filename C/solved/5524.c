#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        char str[21];
        scanf("%s", str);
        for(int i = 0; str[i] != '\0'; i++){
            if(str[i] >= 'A' && str[i] <= 'Z')
                str[i] += 32;
        }
        printf("%s\n", str);
    }
    return 0;
}