#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    char str[505];
    int cnt = 0;
    for(int i = 0; i < n; i++){
        scanf("%s", str);
        for(int j = 0; str[j] != '\0'; j++){
            if(str[j] == 'O' && str[j+1] == 'I'){
                cnt++;
                break;
            }
            if(str[j] == '0' && str[j+1] == '1'){
                cnt++;
                break;
            }
        }
    }
    printf("%d\n", cnt);
}