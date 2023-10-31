#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    char str[55];
    char tmp[55];

    scanf("%s", str);
    for(int i=1; i<n; i++){
        
        scanf("%s", tmp);
        for(int j=0; j<55; j++){
            if(str[j] != tmp[j]){
                str[j] = '?';
            }
        }
    }

    printf("%s\n", str);
}