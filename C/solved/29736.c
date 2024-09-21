#include <stdio.h>

int main(){
    int a,b;
    int k,x;

    scanf("%d %d", &a, &b);
    scanf("%d %d", &k, &x);

    int l = a<k-x?k-x:a;
    int r = b<k+x?b:k+x;

    if(l<=r){
        printf("%d\n", r-l+1);
    }else{
        printf("IMPOSSIBLE\n");
    }
    
}