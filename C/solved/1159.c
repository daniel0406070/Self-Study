#include <stdio.h>

int main(){
    int n;
    char alpha[26] = {0, };
    char str[1004];

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", str);
        alpha[str[0] - 'a']++;
    }

    int flag = 0;
    for(int i = 0; i < 26; i++){
        if(alpha[i] >= 5){
            printf("%c", i + 'a');
            flag = 1;
        }
    }

    if(!flag){
        printf("PREDAJA");
    }
}