#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<2*n;i++){
        if(n==1){
            printf("*");
            break;
        }
        for(int j=0;j<n;j++){
            if((i+j)%2==0) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
}