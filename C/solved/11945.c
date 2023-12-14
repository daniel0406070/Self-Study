#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main(){
    int n,m;
    scanf("%d %d", &n, &m);

    char *arr=(char*)malloc(sizeof(char)*m);
    for(int i=0; i<n; i++){
        scanf("%s", arr);

        for(int j=m-1; j>=0; j--){
            printf("%c", arr[j]);
        }
        printf("\n");
    }

    free(arr);
}