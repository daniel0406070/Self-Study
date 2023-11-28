#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);

    if(n==1){
        printf("*");
        return 0;
    }

    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++) printf(" ");
        printf("*");
        for(int j=0; j<i*2-1; j++) printf(" ");
        if(i!=0) printf("*");
        printf("\n");
    }
    if(n>1) for(int i=0; i<n*2-1; i++) printf("*");
}