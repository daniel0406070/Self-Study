#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char rick[7][100]={
    "Never gonna give you up",
    "Never gonna let you down",
    "Never gonna run around and desert you",
    "Never gonna make you cry",
    "Never gonna say goodbye",
    "Never gonna tell a lie and hurt you",
    "Never gonna stop"
};

int main(){
    int n, c;
    scanf("%d", &n);
    getchar();

    char a[100]={0,};
    for(int i = 0; i < n; i++){
        fgets(a, 100, stdin);
        if(a[strlen(a)-1] == '\n') a[strlen(a)-1] = '\0';
        c=0;
        for(int j = 0; j < 7; j++) if(strcmp(a, rick[j]) == 0) c=1;
        if(c==0){
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
}