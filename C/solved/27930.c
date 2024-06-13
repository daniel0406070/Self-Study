#include <stdio.h>

char a[2][10]={"YONSEI","KOREA"};
int aidx[2]={0,0};

int main(){
    char str[500005];
    scanf("%s", str);

    for(int i=0; str[i]; i++){
        if(str[i]==a[0][aidx[0]]){
            aidx[0]++;
            if(aidx[0]==6){
                printf("YONSEI");
                return 0;
            }
        }
        if(str[i]==a[1][aidx[1]]){
            aidx[1]++;
            if(aidx[1]==5){
                printf("KOREA");
                return 0;
            }
        }
    }
}