#include <stdio.h>

int main(){
    int n;
    int k;

    scanf("%d", &n);
    scanf("%d", &k);

    int a = (n/100)%k;
    a*=100;

    for(int i = 0; i < n; i++){
        if((a+i)%k == 0){
            printf("%02d\n", i);
            break;
        }
    }
    
}