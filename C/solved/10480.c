#include <stdio.h>

int main(){
    int n;

    int a;
    scanf("%d", &n);    
    for(int i=0; i<n; i++){
        scanf("%d", &a);
        if(a%2==0){
            printf("%d is even\n", a);
        }else{
            printf("%d is odd\n", a);
        }
    }
}