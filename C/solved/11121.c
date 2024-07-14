#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    char a[150], b[150];
    for (int i=1; i<=n; i++){
        scanf("%s %s", a, b);

        int flag = 0;
        for (int j=0; a[j]!='\0'; j++){
            if (a[j] != b[j]){
                printf("ERROR\n");
                flag = 1;
                break;
            }
        
        }

        if (flag == 0){
            printf("OK\n");
        }
    }

    return 0;
}