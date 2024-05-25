#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    int max = 0;
    int count = 0;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]>arr[j]){
                count++;
            }
            else{
                break;
            }
        }
        if(count>max){
            max = count;
        }
        count = 0;
    }

    printf("%d\n", max);
}