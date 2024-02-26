#include <stdio.h>

int main(){
    int a[3];

    for(int i = 0; i < 3; i++){
        scanf("%d", &a[i]);
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            if(a[j] > a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    if(a[0]==a[1] && a[1]==a[2]){
        printf("2\n");
    }else if(a[0]*a[0] + a[1]*a[1] == a[2]*a[2]){
        printf("1\n");
    }else{
        printf("0\n");
    }
}