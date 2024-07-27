#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    char str[100];
    scanf("%s", str);

    int cnt = 0;
    char a[5]={'a', 'i', 'u', 'e', 'o'};

    for(int i=0; i<n; i++){
        for(int j=0; j<5; j++){
            if(str[i] == a[j]){
                cnt++;
                break;
            }
        }
    }
    printf("%d", cnt);
}