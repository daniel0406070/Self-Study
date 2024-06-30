#include <stdio.h>
#include <stdlib.h>

char arr[100001]={0,};
char stack[100001]={0,};
int top;

int main(){
    int n;
    scanf("%d", &n);

    int cnt = 0;
    for(int i = 0; i < n; i++){
        top = 0;
        scanf("%s", arr);

        for(int j = 0; arr[j]; j++){
            if(top && stack[top-1] == arr[j]) top--;
            else stack[top++] = arr[j];
        }

        if(!top) cnt++;
    }

    printf("%d", cnt);
}