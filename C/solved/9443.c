#include <stdio.h>

int alpha[26]={0};

int main(){
    int n;
    scanf("%d", &n);

    char str[40];
    while(n--){
        scanf("%s", str);
        alpha[str[0]-'A']++;
    }

    int cnt=0;
    for(int i=0; i<26; i++){
        if(alpha[i]>0) cnt++;
        else break;
    }

    printf("%d\n", cnt);
}