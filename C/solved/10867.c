#include <stdio.h>

int main(){
    int n;
    int arr[2001] = {0,};
    int input;

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &input);
        arr[input+1000]++;
    }

    for(int i=0; i<2001; i++){
        if(arr[i] != 0){
            printf("%d ", i-1000);
        }
    }
}