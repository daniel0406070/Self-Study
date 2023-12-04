#include <stdio.h>
#include <math.h>


int main(){
    int n=32768;

    printf("%d\n",n);
    for(int i=0;i<n;i++){
        printf("100000 ");
    }
    printf("\n");

    printf("%d\n",n);
    for(int i=1;i<=n;i++){
        printf("%d ",i);
    }
}
