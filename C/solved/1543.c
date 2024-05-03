#include <stdio.h>
#include <string.h>

int main(){
    char str[2501];
    char pattern[51];

    scanf("%[^\n]s", str);
    getchar();
    scanf("%[^\n]s", pattern);

    int cnt=0;
    int str_len = strlen(str);
    int pattern_len = strlen(pattern);

    for(int i=0; i<str_len-pattern_len+1; i++){
        if(str[i] == pattern[0]){
            int flag = 1;
            for(int j=1; j<pattern_len; j++){
                if(str[i+j] != pattern[j]){
                    flag = 0;
                    break;
                }
            }
            if(flag){
                cnt++;
                i += pattern_len-1;
            }
        }
    }
   

    printf("%d", cnt);
}