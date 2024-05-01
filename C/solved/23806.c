#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);

    for(int i=0; i<5*n; i++){
        for(int j=0; j<5*n; j++){
            if(i>=n&&i<4*n&&j>=n&&j<4*n) printf(" ");
            else printf("@");
        }
        printf("\n");
    }
}