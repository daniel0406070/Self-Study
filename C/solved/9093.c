#include <stdio.h>
#include <string.h>

int main(){
    int n;
    scanf("%d", &n);

    char arr[1002]={0,};
    for(int i=0; i<n; i++){
        scanf(" %[^\n]", arr);

        char *ptr = strtok(arr, " ");
        while(ptr != NULL){
            int len = strlen(ptr);
            for(int j=len-1; j>=0; j--){
                printf("%c", ptr[j]);
            }
            printf(" ");
            ptr = strtok(NULL, " ");
        }
        printf("\n");
    }
}