#include <stdio.h>
#include <string.h>
#include <math.h>

int alpha[26]={0,};

int main(){
    int n;
    char str[10];
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%s", str);
        int len = strlen(str);
        for(int j=0; j<len; j++){
            alpha[str[j]-'A']+=pow(10, len-j-1);
        }
    }


    int max;
    int max_num = 0;
    int sum=0;
    for (int i = 9; i >= 0; i--){
        max=0;
        for(int j=0; j<26; j++){
            if(alpha[j]>max){
                max=alpha[j];
                max_num=j;
            }
        }
        if(max==0) break;
        alpha[max_num]=0;
        sum+=max*i;
    }

    printf("%d", sum);
}